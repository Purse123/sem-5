#include "iterative.hpp"
#include <iostream>

int main() {
  Iterative it;
    
  // GCD
  int GCD_A = 20;
  int GCD_B = 16;
    
  // Fibonacci
  int FIB_N = 8;
    
  // Sequential search
  int SeqSearch_Size = 5;
  int SeqSearch_Arr[] = {20, 30, 10, 50, 40};
  int SeqSearch_Pos;
  int SeqSearch_Key = 30;
    
  // Bubble sort
  int Bubble_Size = 5;
  int Bubble_Arr[] = {20, 30, 10, 50, 40};
  int Bubble_Pos;
    
  // Selection sort
  int Selection_Size = 5;
  int Selection_Arr[] = {80, 15, 0, 20, 55};
  int Selection_Pos;
    
  // Insertion sort
  int Insertion_Size = 5;
  int Insertion_Arr[] = {85, 15, 18, 25, 40};
  int Insertion_Pos;

  // Fibonacci
  it.Fibonacci(FIB_N);
  it.getCount();
  it.resetCount();
  std::cout << std::endl;
    
  // GCD
  std::cout << "GCD(" << GCD_A << "," << GCD_B << "): " << it.Gcd(GCD_A, GCD_B) << std::endl;
  it.getCount();
  it.resetCount();
  std::cout << std::endl;
  
  // Sequential search
  std::cout << "Sequential search: ";
  it.DisplayArr(SeqSearch_Arr, SeqSearch_Size);
  std::cout << std::endl;
  
  // search and return key index
  SeqSearch_Pos = it.SequentialSearch(SeqSearch_Arr, SeqSearch_Size, SeqSearch_Key);
  if (SeqSearch_Pos != -1) {
    std::cout << "Key " << SeqSearch_Key << " found at position: " << SeqSearch_Pos << std::endl;
  } else {
    std::cout << "Key not found" << std::endl;
  }
  it.getCount();
  it.resetCount();
  std::cout << std::endl;
    
  // Bubble sort
  std::cout << "Bubble Sort:" << std::endl;
  it.BubbleSort(Bubble_Arr, Bubble_Size);
  it.DisplayArr(Bubble_Arr, Bubble_Size);
  std::cout << std::endl;
  it.getCount();
  it.resetCount();
  std::cout << std::endl;
    
  // Selection sort
  std::cout << "Selection Sort:" << std::endl;
  it.SelectionSort(Selection_Arr, Selection_Size);
  it.DisplayArr(Selection_Arr, Selection_Size);
  std::cout << std::endl;
  it.getCount();
  it.resetCount();
  std::cout << std::endl;
    
  // Insertion sort
  std::cout << "Insertion Sort:" << std::endl;
  it.InsertionSort(Insertion_Arr, Insertion_Size);
  it.DisplayArr(Insertion_Arr, Insertion_Size);
  std::cout << std::endl;
  it.getCount();
  it.resetCount();
  std::cout << std::endl;
    
  return 0;
}
