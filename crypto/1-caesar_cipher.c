#include <stdio.h>
#include <ctype.h>

void caesar(char* msg, int shift) {
  shift = (shift % 26 + 26) % 26;         // (a % b) but also handle -ve value
  
  for (int i = 0; msg[i] != '\0'; ++i) {
    if (isalpha(msg[i])) {
      char base = islower(msg[i]) ? 'a' : 'A';

      char normalize = msg[i] - base;
      msg[i] = (normalize + shift) % 26;
      msg[i] = msg[i] + base;
    }
  }
}

int main() {
  char c[] = "This is MsG";
  int shift = 3;
  
  caesar(c, shift);
  printf("%s\n", c);

  caesar(c, -shift);
  printf("%s\n", c);
  return 0;
}
