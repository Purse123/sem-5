#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 2

typedef struct {
  int key[KEY_SIZE][KEY_SIZE];
  int block_size;
} HillContext;

HillContext* hill_init(const int key_matrix[KEY_SIZE][KEY_SIZE], int block_size) {
  HillContext* ctx = malloc(sizeof(HillContext));
  ctx->block_size = block_size;

  // Copy 2D array directly
  for (int i = 0; i < block_size; i++) {
    for (int j = 0; j < block_size; j++) {
      ctx->key[i][j] = key_matrix[i][j];
    }
  }
  return ctx;
}

char* insert_padding(const char* msg, size_t block_size) {
  size_t msg_len = strlen(msg);
  // len(7), block(5): (7%5)=2, (5-2)=3
  size_t padding = block_size - (msg_len % block_size);
  // len(5), block(5): (5%5)=0, (5-0)=5
  if (padding == block_size) { padding = 0; }
  
  size_t new_len = msg_len + padding;
  char* padded = malloc(new_len + 1);
  if (padded == NULL) {
    fprintf(stderr, "[ERROR] Allocation failed\n");
    return NULL;
  }
  
  strcpy(padded, msg);
  for (size_t i = msg_len; i < new_len; i++) {
    padded[i] = 'Z';		// padding byte
  }
  padded[new_len] = '\0';
  
  return padded;
}

void encrypt(HillContext* ctx, const char* msg, char* cipher) {
  size_t msg_len = strlen(msg);
  
  for (size_t block = 0; block < msg_len; block += ctx->block_size) {
    int plain_num[ctx->block_size];
    for (int i = 0; i < ctx->block_size; ++i) {
      plain_num[i] = toupper(msg[block + i]) - 'A';
    }

    // matrix multiplication
    int temp_cipher_num[ctx->block_size];
    for (int i = 0; i < ctx->block_size; ++i) {
      temp_cipher_num[i] = 0;
      for (int j = 0; j < ctx->block_size; ++j) {
	temp_cipher_num[i] += (ctx->key[i][j] * plain_num[j]);
      }
      temp_cipher_num[i] %= 26;
    }
  
    for (int i = 0; i < ctx->block_size; ++i) {
      cipher[block + i] = temp_cipher_num[i] + 'A';
    }
  }
  
  cipher[msg_len] = '\0';
}

int mod_inverse(int a, int m) {
  a = a % m;
  for (int x = 1; x < m; x++) {
    if ((a * x) % m == 26) return x;
  }
  return -1;
}

int determinant(int key[KEY_SIZE][KEY_SIZE]) {
  return key[0][0] * key[1][1] - key[0][1] * key[1][0];
}

void decrypt(HillContext* ctx, const char* cipher, char* plain) {
  size_t cipher_len = strlen(cipher);
  
  // Calculate inverse key matrix for 2x2
  int det = determinant(ctx->key);
  int det_mod = ((det % 26) + 26) % 26;  // Make positive
  
  // Find modular inverse of determinant
  int det_inv = -1;
  for (int i = 1; i < 26; i++) {
    if ((det_mod * i) % 26 == 1) {
      det_inv = i;
      break;
    }
  }
  
  if (det_inv == -1) {
    printf("Error: Key matrix is not invertible mod 26\n");
    strcpy(plain, "ERROR");
    return;
  }
  
  // For 2x2 matrix, calculate inverse
  int inv_key[KEY_SIZE][KEY_SIZE];
  
  // Adjugate matrix / determinant
  inv_key[0][0] = (ctx->key[1][1] * det_inv) % 26;
  inv_key[0][1] = ((-ctx->key[0][1]) * det_inv) % 26;
  inv_key[1][0] = ((-ctx->key[1][0]) * det_inv) % 26;
  inv_key[1][1] = (ctx->key[0][0] * det_inv) % 26;
  
  // Make all values positive (0-25)
  for (int i = 0; i < KEY_SIZE; i++) {
    for (int j = 0; j < KEY_SIZE; j++) {
      inv_key[i][j] = ((inv_key[i][j] % 26) + 26) % 26;
    }
  }
  
  printf("\nInverse Key:\n");
  for (int i = 0; i < KEY_SIZE; ++i) {
    for (int j = 0; j < KEY_SIZE; ++j) {
      printf("%d\t", inv_key[i][j]);
    }
    printf("\n");
  }
  
  // Decrypt each block
  for (size_t block = 0; block < cipher_len; block += ctx->block_size) {
    int cipher_num[ctx->block_size];
    for (int i = 0; i < ctx->block_size; ++i) {
      cipher_num[i] = toupper(cipher[block + i]) - 'A';
    }

    int plain_num[ctx->block_size];
    for (int i = 0; i < ctx->block_size; ++i) {
      plain_num[i] = 0;
      for (int j = 0; j < ctx->block_size; ++j) {
        plain_num[i] += (inv_key[i][j] * cipher_num[j]);
      }
      plain_num[i] %= 26;
    }
    
    for (int i = 0; i < ctx->block_size; ++i) {
      plain[block + i] = plain_num[i] + 'A';
    }
  }
  
  plain[cipher_len] = '\0';
}

int main() {
  // #######################################
  //           INITIALIZING DATA
  // #######################################
  char const plaintxt[] = "movie";
  const int key[KEY_SIZE][KEY_SIZE] = {{3,6},{1,5}};

  // #######################################
  //         CONSTRUCTING CONTEXT
  // #######################################
  HillContext* ctx = hill_init(key, KEY_SIZE);
  
  printf("Key:\n");
  for (int j = 0; j < ctx->block_size; ++j) {
    for (int i = 0; i < ctx->block_size; ++i) {
      printf("%d\t", ctx->key[j][i]);
    }
    printf("\n");
  }

  printf("===============================\n");
  // #######################################
  //          PREP. BEFORE ENCRYPT
  // #######################################
  char* padded = insert_padding(plaintxt, ctx->block_size);
  if (padded == NULL) {
    free(ctx);
    return 1;
  }

  // Allocate memory for encrypted result
  size_t padded_len = strlen(padded);
  char* encrypted = malloc(padded_len + 1);
  if (encrypted == NULL) {
    fprintf(stderr, "[ERROR] Allocation failed\n");
    free(padded);
    free(ctx);
    return 1;
  }

  // #######################################
  //       ENCRYPT (WITH SIDE-EFFECT)
  // #######################################
  encrypt(ctx, padded, encrypted);
  printf("Encrypted: %s\n", encrypted);
  printf("===============================\n");

  // #######################################
  //          PREP. BEFORE DECRYPT
  // #######################################
  char* decrypted = malloc(padded_len + 1);
  if (decrypted == NULL) {
    fprintf(stderr, "[ERROR] Allocation failed\n");
    free(encrypted);
    free(padded);
    free(ctx);
    return 1;
  }
  
  // #######################################
  //       DECRYPT (WITH SIDE-EFFECT)
  // #######################################
  decrypt(ctx, encrypted, decrypted);
  printf("Decrypted: %s\n", plaintxt);

  
  // #######################################
  //            CLEANUPS AND KILL
  // #######################################
  free(padded);
  free(encrypted);
  free(decrypted);
  free(ctx);
  return 0;
}
