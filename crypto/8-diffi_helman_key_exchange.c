#include <stdio.h>
#include <math.h>

// #######################################
//      MODULAR EXPONENTIATION
// #######################################
long long mod_pow(long long base, long long exp, long long mod) {
  long long result = 1;
  
  while (exp > 0) {
    if (exp % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp = exp / 2;
  }
  
  return result;
}

// #######################################
//                MAIN
// #######################################
int main() {
  // #######################################
  //         PUBLIC PARAMETERS
  // #######################################
  int p = 907;
  int g = 709;

  // #######################################
  //         USER A (ALICE)
  // #######################################
  int Priv_A = 248;
  long long Pub_A = mod_pow(g, Priv_A, p);
  
  // #######################################
  //         USER B (BOB)
  // #######################################
  int Priv_B = 539;
  long long Pub_B = mod_pow(g, Priv_B, p);
  
  printf("Public Parameters:\n");
  printf("p = %d\n", p);
  printf("g = %d\n", g);
  
  printf("\nKey Generation:\n");
  printf("Alice\nprivate key: %d\n", Priv_A);
  printf("public key: %lld\n", Pub_A);
  
  printf("Bob\nprivate key: %d\n", Priv_B);
  printf("public key: %lld\n", Pub_B);
  
  // #######################################
  //       COMPUTE SHARED SECRET
  // #######################################
  long long KA = mod_pow(Pub_B, Priv_A, p);
  long long KB = mod_pow(Pub_A, Priv_B, p);

  printf("Shared Secret\n");
  printf("Alice comp key: %lld\n", KA);
  printf("Bob comp key:   %lld\n", KB);

  /* VERIFICATION */
  if (KA != KB) {
    printf("\n[ERROR] Keys don't match!\n");
    return 1;
  } else {
    printf("\n[SUCCESS] Shared secret established: %lld\n", KA);
  }

  printf("Programmed by: Pierce Neupane\n");
  return 0;
}
