#include <stdio.h>
#include <stdlib.h>

void extended_gcd(int a, int b, int *gcd, int *x, int *y) {
  if (b == 0) {
    *gcd = a;
    *x = 1;
    *y = 0;
    return;
  }
  
  int x1, y1;
  extended_gcd(b, a % b, gcd, &x1, &y1);
  
  *x = y1;
  *y = x1 - (a / b) * y1;
}

int main() {
  int a, b;
  int gcd, x, y;

  printf("Enter first and second number: ");
  scanf("%d%d", &a, &b);
  
  printf("===================================\n");  
  extended_gcd(a, b, &gcd, &x, &y);
  
  printf("gcd(%d, %d) = %d\n", a, b, gcd);
  printf("Equation: %d = %d*(%d) + %d*(%d)\n", gcd, a, x, b, y);
 
  return 0;
}
