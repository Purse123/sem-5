#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  int n = 10, i, k = 2;
  float r[10], mean = 0, num = 0, den = 0;

  srand(time(0));

  printf("Random Numbers:\n");
  for(i = 0; i < n; i++) {
    r[i] = (float)rand() / RAND_MAX;
    printf("%.3f ", r[i]);
    mean += r[i];
  }

  mean /= n;

  for(i = 0; i < n-k; i++)
    num += (r[i] - mean) * (r[i+k] - mean);

  for(i = 0; i < n; i++)
    den += (r[i] - mean) * (r[i] - mean);

  printf("\nAutocorrelation = %f\n", num / den);
  float Z = (num / den) * sqrt(n);
  printf("Z = %f\n", Z);
  printf("_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");

  return 0;
}
