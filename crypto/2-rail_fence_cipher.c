/*
 *@breif: rail fence cipher
 *
 *@example:
 *@input: PIERCE
 *
 * P . . . C .     <- rail 0
 * . I . R . E     <- rail 1
 * . . E . . .     <- rail 2
 *
 *@output: PCIREE
 *@author: github.com/purse123
*/
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_RAILS 3
/* cycle = 2 * (no_rails - 1); */
/* rail = i % cycle */
/* if (rail >= numRails) rail = cycle - rail */

void rail_fence(char* msg, int no_rail, char rails[MAX_RAILS][MAX_LEN]) {
  int len = strlen(msg);
  int cycle = 2 * (no_rail - 1);
  int rail_state[MAX_RAILS] = {0};
  
  for (int i = 0; i < len; ++i) {
    int rail = ((i % cycle) + cycle) % cycle;

    if (rail >= no_rail) { rail = cycle - rail; }
    
    rails[rail][rail_state[rail]++] = msg[i];
  }

  for (int r = 0; r < no_rail; r++) {
    rails[r][rail_state[r]] = '\0';
  }
}

int main() {
  char *msg = "PIERCE"; 
  char res[MAX_RAILS][MAX_LEN];
  rail_fence(msg, 3, res);

  printf("=====================================\n");
  printf("Original plain text: %s\n", msg);
  printf("=====================================\n");
  printf("Encrypt:\n");
  for (int r = 0; r < 3; r++) { printf("Rail %d: %s\n", r, res[r]); }

  printf("Output cipher text: ");
  for (int r = 0; r < 3; r++) { printf("%s", res[r]); } printf("\n");
  printf("=====================================\n");
  printf("Decrypt:\n");
  rail_fence_decrypt(msg, 3, res);
  for (int r = 0; r < 3; r++) { printf("Rail %d: %s\n", r, res[r]); }
  
  return 0;
}
