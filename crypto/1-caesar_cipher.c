#include <stdio.h>
#include <ctype.h>

// #######################################
//           ENCRYPT FUNCTION
// #######################################
void encrypt_caesar(char* msg, int shift) {
  shift = (shift % 26 + 26) % 26;         // Normalize shift to 0-25
  
  for (int i = 0; msg[i] != '\0'; ++i) {
    if (isalpha(msg[i])) {
      char base = islower(msg[i]) ? 'a' : 'A';
      char normalized = msg[i] - base;
      msg[i] = (normalized + shift) % 26;
      msg[i] = msg[i] + base;
    }
  }
}

// #######################################
//           DECRYPT FUNCTION
// #######################################
void decrypt_caesar(char* msg, int shift) {
  // Decryption is just encryption with negative shift
  encrypt_caesar(msg, -shift);
}

// #######################################
//                MAIN
// #######################################
int main() {
  char c[] = "Purse";
  int shift = 3;
  
  printf("Original: %s\n", c);
  
  // Encrypt
  encrypt_caesar(c, shift);
  printf("Encrypted: %s\n", c);
  
  // Decrypt
  decrypt_caesar(c, shift);
  printf("Decrypted: %s\n", c);

  printf("Programmed by: Pierce Neupane\n");
  return 0;
}
