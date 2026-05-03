#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, n = 10;
  float r[10];
  int freq[5] = {0};
  float chi = 0, E = 2.0;

  srand(time(0));

  printf("Random Numbers:\n");
  for(i = 0; i < n; i++) {
    r[i] = (float)rand() / RAND_MAX;
    printf("%.3f ", r[i]);
  }

  for(i = 0; i < n; i++) {
    if(r[i] < 0.2) freq[0]++;
    else if(r[i] < 0.4) freq[1]++;
    else if(r[i] < 0.6) freq[2]++;
    else if(r[i] < 0.8) freq[3]++;
    else freq[4]++;
  }

  for(i = 0; i < 5; i++)
    chi += ((freq[i] - E) * (freq[i] - E)) / E;

  printf("\nChi-Square = %f\n", chi);

  printf("_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");

  return 0;
}
