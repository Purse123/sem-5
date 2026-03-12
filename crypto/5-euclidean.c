#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
  a = abs(a); b = abs(b);

  if (b > a) {
    int temp = a;
    a = b;
    b = temp;
  }
  
  while (b != 0) {
    int remainder = a % b;
    a = b;
    b = remainder;
  }
  
  return a;
}

int main() {
  int a, b;  
  printf("Enter first and second number: ");
  scanf("%d%d", &a, &b);
 
  printf("===================================\n");
  int result = gcd(a, b);
  printf("gcd(%d, %d) = %d\n", a, b, result);
  
  return 0;
}
