#include <stdio.h>

int main() {
  int n = 10, i;
  float arrival_rate = 2.0, service_rate = 3.0;
  float L, Lq, W, Wq, rho;

  // Traffic intensity
  rho = arrival_rate / service_rate;

  // Queue formulas (M/M/1 system)
  L  = rho / (1 - rho);              // Avg customers in system
  Lq = (rho * rho) / (1 - rho);     // Avg customers in queue
  W  = 1 / (service_rate - arrival_rate);
  Wq = arrival_rate / (service_rate * (service_rate - arrival_rate));

  printf("Arrival Rate = %.2f\n", arrival_rate);
  printf("Service Rate = %.2f\n", service_rate);
  printf("Traffic Intensity = %.2f\n\n", rho);

  printf("Average customers in system = %.2f\n", L);
  printf("Average customers in queue = %.2f\n", Lq);
  printf("Average time in system = %.2f\n", W);
  printf("Average waiting time in queue = %.2f\n", Wq);

  printf("_______________________________\n");
  printf("Programmed by: Pierce Neupane\n");

  return 0;
}
