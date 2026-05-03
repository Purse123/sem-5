#include <stdio.h>

int main() {
  int n, i;
  float r[50], Dplus = 0, Dminus = 0, D;

  printf("Enter number of random numbers: ");
  scanf("%d", &n);

  printf("Enter random numbers:\n");
  for(i = 0; i < n; i++)
    scanf("%f", &r[i]);

  // Sorting
  for(i = 0; i < n-1; i++) {
    for(int j = i+1; j < n; j++) {
      if(r[i] > r[j]) {
	float t = r[i];
	r[i] = r[j];
	r[j] = t;
      }
    }
  }

  printf("\nIndex\tRi\t\ti/n\t\ti/n-Ri\t\tRi-(i-1)/n\n");

  for(i = 0; i < n; i++) {
    float in = (float)(i+1)/n;
    float in_1 = (float)i/n;

    float d1 = in - r[i];
    float d2 = r[i] - in_1;

    if(d1 > Dplus) Dplus = d1;
    if(d2 > Dminus) Dminus = d2;

    printf("%d\t%.3f\t\t%.3f\t\t%.3f\t\t%.3f\n",
	   i+1, r[i], in, d1, d2);
  }

  D = (Dplus > Dminus) ? Dplus : Dminus;

  printf("\nD+ = %.3f\n", Dplus);
  printf("D- = %.3f\n", Dminus);
  printf("D  = %.3f\n", D);

  printf("_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");
  return 0;
}
