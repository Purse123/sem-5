#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 6

void vernem_cipher(char *text, char *key) {
  size_t len = strlen(text);
    
  if (len != strlen(key)) return;

  for (size_t i = 0; i < len; ++i) {
    text[i] = ((toupper(text[i]) - 'A') ^ (toupper(key[i]) - 'A')) % 26 + 'A';
  }
}

int main() {
  char msg[SIZE] = "Purse";
  char key[SIZE] = "KCBAD";

  printf("Original Msg: %s\nKey: %s\n", msg, key);
  vernem_cipher(msg, key);
  
  printf("After encrption\n");
  printf("Msg: %s\n", msg);

  vernem_cipher(msg, key);
  printf("After decryption\n");
  printf("Msg: %s\n", msg);

  return 0;
}
