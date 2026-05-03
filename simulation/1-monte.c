#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 10000, i, count = 0;
  float x, y, pi;

  for(i = 0; i < n; i++) {
    x = (float)rand() / RAND_MAX;
    y = (float)rand() / RAND_MAX;

    if(x*x + y*y <= 1)
      count++;
  }

  pi = (4.0 * count) / n;

  printf("Total Points = %d\n", n);
  printf("Points inside circle = %d\n", count);
  printf("Estimated Pi = %f\n", pi);

  printf("_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");
  return 0;
}
