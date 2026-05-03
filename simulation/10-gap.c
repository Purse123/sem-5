#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  int n, i, last = -1, gap;
  float r[100];
  int Fo[10] = {0};
  float Fe[10], D = 0;

  printf("Enter number of random numbers: ");
  scanf("%d", &n);

  srand(time(0));

  printf("\nRandom Numbers:\n");
  for(i = 0; i < n; i++) {
    r[i] = (float)rand() / RAND_MAX;
    printf("%.3f ", r[i]);
  }

  // Find gaps for interval [0.2, 0.5)
  for(i = 0; i < n; i++) {
    if(r[i] >= 0.2 && r[i] < 0.5) {
      if(last != -1) {
	gap = i - last - 1;
	if(gap < 10)
	  Fo[gap]++;
      }
      last = i;
    }
  }

  float p = 0.3; // probability of interval [0.2,0.5)
  int total_gaps = 0;

  for(i = 0; i < 10; i++)
    total_gaps += Fo[i];

  printf("\n\nGap\tFo\tFe\t|Fo-Fe|\n");

  for(i = 0; i < 10; i++) {
    Fe[i] = total_gaps * p * pow((1 - p), i);

    float diff = fabs(Fo[i] - Fe[i]);
    if(diff > D) D = diff;

    printf("%d\t%d\t%.2f\t%.2f\n", i, Fo[i], Fe[i], diff);
  }

  printf("\nTest Statistic D = %.3f\n", D);

  printf("_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");

  return 0;
}
