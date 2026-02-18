#include <iostream>
#include <vector>

class IterativeAlgo {
private:
  int count_ = 0;
  std::vector<int> data_ = {0, 1, 2, 3, 4};
  
public:
  IterativeAlgo() = default;

  std::vector<int> fibonacci(int n) {
    int a = 0, b = 1, temp;
    std::vector<int> res;
    
    if (n == 0) return res;
    res.push_back(a);
    if (n == 1) return res;
    res.push_back(b);
    
    for (int i = 2; i < n; ++i) {
      temp = a + b;
      a = b;
      b = temp;
      res.push_back(temp);
    }

    return res;
  }
  
  int gcd(int a, int b) {
    int temp;
    while (b) {
      temp = a % b;
      a = b;
      b = temp;
    }
    return a;
  }
};

int main() {
  int n;
  IterativeAlgo a;

  // fibonacci
  std::cout << "Enter nth term of fibonacci: ";
  std::cin >> n;
  for (const int data: a.fibonacci(n)) {
    std::cout << data << " ";
  }
  std::cout << std::endl;

  // gcd
  int gcd_x, gcd_y;
  std::cout << "For GCD(a, b)\n"
	    << "Enter a and b: \n";
  std::cin >> gcd_x >> gcd_y;
  std::cout << "GCD = " << a.gcd(gcd_x, gcd_y) << std::endl;
  
  return 0;
}
