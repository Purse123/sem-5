#include "divideConquer.hpp"
#include <iostream>
using namespace std;

int main() {
  DivideConquer dc;
    
  int BS_Idx;
  int BS_Size = 5;
  int BS_Key = 20;
  int BS_Arr[] = {10, 20, 30, 40, 50};
    
  int MinMax_Size = 5;
  int MinMax_Arr[] = {5, 2, 8, 1, 9};
  MinMaxRes MinMax_Result;

  int Merge_Size = 7;
  int Merge_Arr[] = {64, 34, 25, 12, 22, 11, 90};
    
  int Quick_Size = 7;
  int Quick_Arr[] = {64, 34, 25, 12, 22, 11, 90};
    
  int Heap_Size = 7;
  int Heap_Arr[] = {64, 34, 25, 12, 22, 11, 90};
    
  // Binary Search
  cout << "Binary Search: ";
  dc.displayArr(BS_Arr, BS_Size);
  cout << endl;
  BS_Idx = dc.binarySearch(BS_Arr, 0, BS_Size, BS_Key);
  if (BS_Idx == -1) {
    cout << "Key not found" << endl;
  } else {
    cout << "Key found on index: " << BS_Idx << endl;
  }
  dc.getCount();
  dc.resetCount();
  cout << endl;
    
  // Min Max Search
  cout << "Min Max Search: ";
  dc.displayArr(MinMax_Arr, MinMax_Size);
  cout << endl;
    
  MinMax_Result = dc.minMax(MinMax_Arr, 0, MinMax_Size - 1);
  cout << "Minimum: " << MinMax_Result.min << endl;
  cout << "Maximum: " << MinMax_Result.max << endl;
    
  dc.getCount();
  dc.resetCount();
  cout << endl;

  // Merge Sort
  cout << "Merge Sort: ";
  dc.displayArr(Merge_Arr, Merge_Size);
  cout << endl;
    
  dc.mergeSort(Merge_Arr, 0, Merge_Size - 1);
  cout << "Sorted: ";
  dc.displayArr(Merge_Arr, Merge_Size);
  cout << endl;
    
  dc.getCount();
  dc.resetCount();
  cout << endl;
    
  // Quick Sort
  cout << "Quick Sort: ";
  dc.displayArr(Quick_Arr, Quick_Size);
  cout << endl;
    
  dc.quickSort(Quick_Arr, 0, Quick_Size - 1);
  cout << "Sorted: ";
  dc.displayArr(Quick_Arr, Quick_Size);
  cout << endl;
    
  dc.getCount();
  dc.resetCount();
  cout << endl;
    
  // Heap Sort
  cout << "Heap Sort: ";
  dc.displayArr(Heap_Arr, Heap_Size);
  cout << endl;
    
  dc.heapSort(Heap_Arr, Heap_Size);
  cout << "Sorted: ";
  dc.displayArr(Heap_Arr, Heap_Size);
  cout << endl;
    
  dc.getCount();
  dc.resetCount();
  cout << endl;
    
  return 0;
}
