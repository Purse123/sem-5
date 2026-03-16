#include <stdio.h>
#define VAL 17
#define PLAINTEXT 609

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

// Modular exponentiation: (base^exp) % mod
long long mod_exp(long long base, long long exp, long long mod) {
  long long result = 1;
  base = base % mod;

  while (exp > 0) {
    if (exp % 2 == 1)
      result = (result * base) % mod;

    base = (base * base) % mod;
    exp = exp / 2;
  }

  return result;
}

int mod_inverse(int e, int phi) {
  for (int d = 2; d < phi; d++)
    if ((e * d) % phi == 1) return d;
  return -1;
}

int main() {
  int p = 97;
  int q = 9973;
  
  int n = p * q;
  int phi = (p - 1) * (q - 1);
  
  int e = VAL;
  while (gcd(e, phi) != 1) e++;

  int d = mod_inverse(e, phi);

  printf("Public key: \n");
  printf("e: %d\nn: %d\n\n", e, n);
  printf("Private key: \n");
  printf("d: %d\nn: %d\n\n", d, n);

  int msg = PLAINTEXT;

  long long encrypted = mod_exp(msg, e, n);
  long long decrypted = mod_exp(encrypted, d, n);

  printf("Original Msg: %d\n", msg);
  printf("Encrypted Msg: %lld\nDecrypted Msg: %lld\n", encrypted, decrypted);
  
  return 0;
}
