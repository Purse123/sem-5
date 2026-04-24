#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;
using namespace std::complex_literals;

void simpleDFT(vector<complex<double>>& data) {
  int n = data.size();
  vector<complex<double>> result(n);
    
  for (int k = 0; k < n; k++) {
    complex<double> sum = 0;
    for (int t = 0; t < n; t++) {
      double angle = -2 * M_PI * k * t / n;
      complex<double> w = cos(angle) + sin(angle) * 1i;
      sum += data[t] * w;
    }
    result[k] = sum;
  }
  data = result;
}


void explainedFFT(vector<complex<double>>& data, int depth = 0) {
  int n = data.size();
    
  // Print indentation for visual clarity
  string indent(depth * 2, ' ');
    
  cout << indent << "FFT called with " << n << " points\n";
    
  // Base case: if only 1 element, return (nothing to do)
  if (n <= 1) {
    cout << indent << "  Base case: single point, returning\n";
    return;
  }
    
  // STEP 1: Split into EVEN and ODD indices
  vector<complex<double>> even(n/2), odd(n/2);
    
  cout << indent << "  Splitting into:\n";
  cout << indent << "    Even indices: ";
  for (int i = 0; i < n/2; i++) {
    even[i] = data[2*i];
    if (i < 4) cout << 2*i << "(" << real(even[i]) << ") ";
  }
  if (n/2 > 4) cout << "...";
  cout << "\n";
    
  cout << indent << "    Odd indices:  ";
  for (int i = 0; i < n/2; i++) {
    odd[i] = data[2*i + 1];
    if (i < 4) cout << 2*i+1 << "(" << real(odd[i]) << ") ";
  }
  if (n/2 > 4) cout << "...";
  cout << "\n";
    
  // STEP 2: Recursively compute FFT on the halves
  cout << indent << "  Recursively processing EVEN half...\n";
  explainedFFT(even, depth + 1);
    
  cout << indent << "  Recursively processing ODD half...\n";
  explainedFFT(odd, depth + 1);
    
  // STEP 3: Combine results using the "twiddle factor"
  cout << indent << "  Combining results:\n";
    
  for (int i = 0; i < n/2; i++) {
    double angle = -2 * M_PI * i / n;
    complex<double> twiddle = cos(angle) + sin(angle) * 1i;
        
    complex<double> t = twiddle * odd[i];
    complex<double> original_even = even[i];
    complex<double> original_odd = odd[i];
        
    data[i] = even[i] + t;
    data[i + n/2] = even[i] - t;
        
    cout << indent << "    data[" << i << "] = even[" << i << "] + twiddle×odd[" << i << "]\n";
    cout << indent << "    data[" << i+n/2 << "] = even[" << i << "] - twiddle×odd[" << i << "]\n";
  }
}


int main() {
}
