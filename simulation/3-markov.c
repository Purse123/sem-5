#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, steps = 10;
  float P[2][2] = {{0.7, 0.3},
		   {0.4, 0.6}};
  int state = 0;  // initial state

  printf("Initial State: %d\n", state);

  for(i = 0; i < steps; i++) {
    float r = (float)rand() / RAND_MAX;

    float cumulative = 0;

    for(j = 0; j < 2; j++) {
      cumulative += P[state][j];

      if(r <= cumulative) {
	state = j;
	break;
      }
    }

    printf("Step %d -> State %d\n", i+1, state);
  }

  printf("_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");

  return 0;
}
