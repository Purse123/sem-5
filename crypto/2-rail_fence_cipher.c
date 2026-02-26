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
#define NUM_RAIL 3
/* cycle = 2 * (no_rails - 1); */
/* rail = i % cycle */
/* if (rail >= numRails) rail = cycle - rail */

void encrypt(char* msg, int no_rails, char rails[NUM_RAIL][MAX_LEN], int rail_state[]) {
  int len = strlen(msg);
  int cycle = 2 * (no_rails - 1);
  
  // Initialize rail_state
  for (int r = 0; r < no_rails; r++) { rail_state[r] = 0; }
  
  for (int i = 0; i < len; ++i) {
    int rail = i % cycle;
    if (rail >= no_rails) { rail = cycle - rail; }
    
    rails[rail][rail_state[rail]++] = msg[i];
  }
  
  // Null terminate each rail
  for (int r = 0; r < no_rails; r++) { 
    rails[r][rail_state[r]] = '\0'; 
  }
}

void decrypt(char* msg, int no_rails, char rails[NUM_RAIL][MAX_LEN], int rail_state[]) {
  int read_pos[NUM_RAIL];
  for (int r = 0; r < no_rails; r++) { read_pos[r] = 0; }
  
  int len = 0;
  for (int r = 0; r < no_rails; r++) { len += rail_state[r]; }
  
  int cycle = 2 * (no_rails - 1);
  int msg_idx = 0;

  for (int i = 0; i < len; ++i) {
    int rail = i % cycle;
    if (rail >= no_rails) rail = cycle - rail;
    
    msg[msg_idx++] = rails[rail][read_pos[rail]++];
  }
  msg[msg_idx] = '\0';
}

int main() {
  char msg[] = "PIERCE"; 
  char rails[NUM_RAIL][MAX_LEN] = {0};
  int rail_state[NUM_RAIL] = {0};
  char cipher_text[MAX_LEN] = {0};
  
  printf("=====================================\n");
  printf("Original plain text: %s\n", msg);
  printf("=====================================\n");

  printf("Encrypt:\n");
  encrypt(msg, NUM_RAIL, rails, rail_state);

  // display rails
  for (int r = 0; r < NUM_RAIL; r++) {
    printf("Rail %d: %s\n", r, rails[r]);
  }

  strcpy(cipher_text, "");
  for (int r = 0; r < NUM_RAIL; r++) { strcat(cipher_text, rails[r]); }
  
  printf("Output cipher test: %s\n", cipher_text);
  
  printf("=====================================\n");
  decrypt(msg, NUM_RAIL, rails, rail_state);
  printf("Decrypt: %s\n", msg);
  
  return 0;
}
