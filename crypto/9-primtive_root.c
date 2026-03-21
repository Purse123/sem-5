#include <stdio.h>
#include <math.h>

typedef unsigned int uint;
uint mod_pow(uint base, uint exp, uint mod) {
  uint result = 1;
  base = base % mod;

  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp = exp / 2;
  }
  return result;
}

int find_primitive_root(uint p) {
  uint phi = p - 1;
  
  // Find prime factors of phi
  uint factors[100];
  uint factor_count = 0;
  uint n = phi;

  // even factor
  if (n % 2 == 0) {
    factors[factor_count++] = 2;
    while (n % 2 == 0) n /= 2;
  }

  // odd factor
  for (uint i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      factors[factor_count++] = i;
      while (n % i == 0) n /= i;
    }
  }

  // remaining prime
  if (n > 2) factors[factor_count++] = n;

  //test primitive roots
  for (uint g = 2; g < p; g++) {
    int is_root = 1;

    for (uint i = 0; i < factor_count; i++) {
      uint exp = phi / factors[i];
      if (mod_pow(g, exp, p) == 1) {
	is_root = 0;
	break;
      }
    }

    if (is_root) return g;
  }
  return -1;
}

int main() {
  uint p;
  printf("Enter a prime number: ");
  scanf("%u", &p);
  
  int root = find_primitive_root(p);
  if (root != -1) printf("Smallest primitive root of %u is: %d\n", p, root);
  else printf("No primitive root found for %u\n", p);
  
  return 0;
}
