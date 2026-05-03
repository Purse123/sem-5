#include <stdio.h>

int main() {
  int n = 10;
  long long a = 1103515245, c = 12345, m = 32768;
  long long x = 5;   // seed
  int i;

  printf("Random Numbers using LCG:\n");

  for(i = 0; i < n; i++) {
    x = (a * x + c) % m;
    printf("%lld\n", x);
  }

  printf("_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");

  return 0;
}
