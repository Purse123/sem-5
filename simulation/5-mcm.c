#include <stdio.h>

int main() {
  int n = 10, i;
  long long a = 13, m = 31;
  long long x = 7;   // seed

  printf("Random Numbers using MCM:\n");

  for(i = 0; i < n; i++) {
    x = (a * x) % m;
    printf("%lld\n", x);
  }

  printf("_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");

  return 0;
}
