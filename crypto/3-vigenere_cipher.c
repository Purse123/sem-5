#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *msg, const char *key) {
  size_t msg_len = strlen(msg);
  size_t key_len = strlen(key);
  
  for (size_t i = 0; i < msg_len; i++) {
    char ch = toupper(msg[i]);
    char key_ch = toupper(key[i % key_len]);

    // (msg-char + key-char) % 26 + 'A'
    msg[i] = ((ch - 'A') + (key_ch - 'A')) % 26 + 'A';
  }
}

void decrypt(char *msg, const char *key) {
  size_t msg_len = strlen(msg);
  size_t key_len = strlen(key);
  
  for (size_t i = 0; i < msg_len; i++) {
    char ch = toupper(msg[i]);
    char key_ch = toupper(key[i % key_len]);

    // (msg-char - key-char + 26) % 26 + 'A'
    msg[i] = ((ch - 'A') - (key_ch - 'A') + 26) % 26 + 'A';
  }
}

int main() {
  char text[] = "hello";
  const char key[] = "KEY";
  
  encrypt(text, key);
  printf("Encrypted: %s\n", text);
  
  decrypt(text, key);
  printf("Decrypteded: %s\n", text);
  
  return 0;
}
