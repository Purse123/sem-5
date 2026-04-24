#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>

#define ROTR(x,n) ((x >> n) | (x << (64 - n)))

typedef uint64_t u64;

bool keyGen = false;
// 8 * 64 = 512 bit hash
u64 hash[8] = {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL};
long double hash_dbl[8];

u64 init_hash[8] = {
    0x6a09e667f3bcc908ULL, 0xbb67ae8584caa73bULL,
    0x3c6ef372fe94f82bULL, 0xa54ff53a5f1d36f1ULL,
    0x510e527fade682d1ULL, 0x9b05688c2b3e6c1fULL,
    0x1f83d9abfb41bd6bULL, 0x5be0cd19137e2179ULL
};

void initial_hash();

uint64_t sigma0(uint64_t x);
uint64_t sigma1(uint64_t x);
uint64_t Ch(uint64_t x, uint64_t y, uint64_t z);
uint64_t Maj(uint64_t x, uint64_t y, uint64_t z);

void pad_msg(const char* msg, unsigned char** padded, size_t* new_len);
void sha512(const char* msg);

int main(int argc, char *argv[]) {
  // -k flag handler
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-k") == 0) {
      keyGen = true;
    }
  }
  if (keyGen) {
    initial_hash();
    return 0;
  }
  
  char msg[] = "Purse";
  sha512(msg);
}

void sha512(const char* msg) {
  unsigned char* padded = NULL;
  size_t new_len = 0;
  
  // Pad msg to 1024-bit block
  pad_msg(msg, &padded, &new_len);
  if (padded == NULL) return;

  printf("=====================================================================\n");
  printf("             Msg | 0x80 | padded 0s | Msg length\n");
  printf("=====================================================================\n");
  
  printf("Padded message (first 16 bytes): ");
  for (size_t i = 0; i < 16; ++i) {
    printf("%02X ", padded[i]);
  }
  printf("\n");

  for (size_t i = 16; i < 111; ++i) {
    printf("%02X ", padded[i]);
  }
  printf("\n");
  
  printf("Last 16 bytes (length field): ");
  for (size_t i = 112; i < 128; i++) {
    printf("%02X ", padded[i]);
  }
  printf("\n");
  
  printf("Padded length: %zu bytes\n", new_len);

  printf("=====================================================================\n");
  printf("                      Core SHA-512\n");
  printf("=====================================================================\n");

  // dividing into blocks
  // 128 byte = 16 * 8 bytes
  // 128 byte = 1024 bit

  // W[0..15]  big endian representation
  u64 W[80];
  for (int i = 0; i < 16; ++i) {
    W[i] = ((u64)padded[i*8 + 0] << 56) |
	   ((u64)padded[i*8 + 1] << 48) |
	   ((u64)padded[i*8 + 2] << 40) |
	   ((u64)padded[i*8 + 3] << 32) |
	   ((u64)padded[i*8 + 4] << 24) |
	   ((u64)padded[i*8 + 5] << 16) |
	   ((u64)padded[i*8 + 6] << 8 ) |
	   ((u64)padded[i*8 + 7]);
  }

  // W[16..79]
  for (int i = 16; i < 80; i++) {
    W[i] = sigma1(W[i-2]) + W[i-7] + sigma0(W[i-15]) + W[i-16];
  }
  
  // [TEST] Print
  printf("\nMessage Schedule W[0..15]:\n");
  for (int i = 0; i < 16; i++) {
    printf("W[%2d] = %016" PRIx64 "\n", i, W[i]);
  }

  // [TODO] Compress 80 round loop
  // [TODO] Update hash
  // [TODO] Final step
  free(padded);
}

void initial_hash() {
  long double OFract[8];
  for (int i = 0; i < 8; ++i) {
    hash_dbl[i] = sqrtl(hash[i]);
    /* hash[i] = (u64)hash_dbl[i]; */

    OFract[i] = hash_dbl[i] - (long long)hash_dbl[i];
    printf("%Lf\t", OFract[i]);

    // 2^n = 1 << n, 64-bit integer so not 1 << 64
    OFract[i] = OFract[i] * (1ULL << 63) * 2.0L;
    hash[i] = (u64)OFract[i];
    printf("%Lf\n", OFract[i]);
  }
  for (int i = 0; i < 8; ++i) {
    printf("hash[%d]: %" PRIx64 "\n", i, hash[i]);
  }
}

/*
 *@method: pad_msg
 *@breif:
 * - need to find no of zero to add
 * - Total should be multiple of 128 bytes
 * [ message ][ 0x80 ][ zeros ][ 16-byte / 128-bit length ]
 */
void pad_msg(const char* msg, unsigned char** padded, size_t* new_len) {
  size_t len = strlen(msg);
  size_t total_len = len + 1 + 16;

  // round up to next multiple of 128
  while (total_len % 128 != 0) {
    total_len++;
  }
  
  *padded = malloc(total_len);
  if (*padded == NULL) {
    printf("Memory allocation failed\n");
    *new_len = 0;
    return;
  }
  
  memcpy(*padded, msg, len);
  
  (*padded)[len] = 0x80;	/* adding 0x80 */
  
  // 16 byte padding by zero
  // Our pointer is at 0x80 now
  size_t idx = len + 1;
  while (idx < total_len - 16) {
    (*padded)[idx++] = 0x00;
  }

  u64 bit_len_low = len * 8;
  u64 bit_len_high = 0;

  // for high bit
  for (int i = 0; i < 8; ++i) {
    (*padded)[idx + i] = (bit_len_high >> (56 - 8 * i)) & 0xFF;
  }
  // for low bit
  for (int i = 0; i < 8; ++i) {
    (*padded)[idx + 8 + i] = (bit_len_low >> (56 - 8 * i)) & 0xFF;
  }
  *new_len = total_len;
}

uint64_t sigma0(uint64_t x) {
  return ROTR(x,1) ^ ROTR(x,8) ^ (x >> 7);
}

uint64_t sigma1(uint64_t x) {
  return ROTR(x,19) ^ ROTR(x,61) ^ (x >> 6);
}

uint64_t Ch(uint64_t x, uint64_t y, uint64_t z) {
    return (x & y) ^ (~x & z);
}

uint64_t Maj(uint64_t x, uint64_t y, uint64_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}
