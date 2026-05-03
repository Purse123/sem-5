#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, n = 10, last = -1, gap;
  float r[10];

  srand(time(0));

  printf("Random Numbers:\n");
  for(i = 0; i < n; i++) {
    r[i] = (float)rand() / RAND_MAX;
    printf("%.3f ", r[i]);
  }

  printf("\nGaps (0.3 to 0.7):\n");

  for(i = 0; i < n; i++) {
    if(r[i] >= 0.3 && r[i] <= 0.7) {
      if(last != -1) {
	gap = i - last - 1;
	printf("%d ", gap);
      }
      last = i;
    }
  }

  printf("\n_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");

  return 0;
}
