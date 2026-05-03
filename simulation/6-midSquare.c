#include <stdio.h>

int main() {
  int n = 10, i;
  long long seed = 1234;
  long long sq, mid;

  printf("Random Numbers using Mid-Square Method:\n");

  for(i = 0; i < n; i++) {
    sq = seed * seed;

    // extract middle 4 digits (for 4-digit seed)
    mid = (sq / 100) % 10000;

    seed = mid;

    printf("%lld\n", seed);
  }

  printf("_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");

  return 0;
}
