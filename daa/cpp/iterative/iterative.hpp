#ifndef ITERATIVE_HPP
#define ITERATIVE_HPP

#include <iostream>

class Iterative {
private:
  int count;
    
  void Swap(int& A, int& B) {
    int Temp = A;
    A = B;
    B = Temp;
    count += 3;
  }
    
public:
  Iterative() : count(0) {}
    
  void getCount() {std::cout << "Imperative analysis: " << count << std::endl;}
    
  void resetCount() {count = 0;}
    
  void DisplayArr(int Arr[], int Size) {
    std::cout << "[";
    for (int i = 0; i < Size; i++) {
      std::cout << " " << Arr[i];
      if (i < Size - 1) std::cout << ", ";
    }
    std::cout << " ]";
  }
    
  int Gcd(int A, int B) {
    count = 0;
    if (A < 0) {
      A = -A;
      count += 2;
    } else {
      count += 1;
    }
        
    if (B < 0) {
      B = -B;
      count += 2;
    } else {
      count += 1;
    }
        
    while (B != 0) {
      count += 1;
      int Temp = A % B;
      count += 1;
      A = B;
      count += 1;
      B = Temp;
      count += 1;
    }
    count += 1;
        
    return A;
  }
    
  void Fibonacci(int N) {
    count = 0;
    int A = 0, B = 1, Temp;
        
    if (N <= 0) {
      count += 1;
      std::cout << "-ve number";
      return;
    }
        
    std::cout << "Fibonacci sequence upto " << N << ": ";
        
    if (N >= 1) {
      count += 1;
      std::cout << A;
    }
        
    if (N >= 2) {
      count += 1;
      std::cout << " " << B;
    }
        
    for (int I = 3; I <= N; I++) {
      count += 1;
      Temp = A + B;
      count += 1;
      std::cout << " " << Temp;
      A = B;
      count += 1;
      B = Temp;
      count += 1;
    }
        
    std::cout << std::endl;
  }
    
  int SequentialSearch(int Arr[], int Size, int Key) {
    count = 0;
    for (int i = 0; i < Size; i++) {
      count += 1;
      if (Arr[i] == Key) {
	count += 1;
	return i;
      }
    }
    count += 1;
    return -1;
  }
    
  void BubbleSort(int Arr[], int Size) {
    count = 0;
    for (int j = 0; j < Size - 1; j++) {
      count += 1;
      for (int i = 0; i < Size - j - 1; i++) {
	count += 1;
	if (Arr[i] > Arr[i + 1]) {
	  count += 1;
	  Swap(Arr[i], Arr[i + 1]);
	}
      }
    }
    count += 1;
  }
    
  void SelectionSort(int Arr[], int Size) {
    count = 0;
    for (int j = 0; j < Size - 1; j++) {
      count += 1;
      int MinIdx = j;
      count += 1;
            
      for (int i = j + 1; i < Size; i++) {
	count += 1;
	if (Arr[i] < Arr[MinIdx]) {
	  count += 1;
	  MinIdx = i;
	  count += 1;
	}
      }
      count += 1;
            
      if (MinIdx != j) {
	count += 1;
	Swap(Arr[j], Arr[MinIdx]);
      }
    }
    count += 1;
  }
    
  void InsertionSort(int Arr[], int Size) {
    count = 0;
    for (int i = 1; i < Size; i++) {
      count += 1;
      int Key = Arr[i];
      count += 1;
      int j = i - 1;
      count += 1;
            
      while (j >= 0 && Arr[j] > Key) {
	count += 1;
	Arr[j + 1] = Arr[j];
	count += 1;
	j--;
	count += 1;
      }
      count += 1;
            
      Arr[j + 1] = Key;
      count += 1;
    }
    count += 1;
  }
};

#endif
