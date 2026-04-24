#ifndef DIVIDECONQUER_HPP
#define DIVIDECONQUER_HPP

#include <iostream>
using namespace std;

struct MinMaxRes {
  int min;
  int max;
};

class DivideConquer {
private:
  int count;
    
  void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid; count += 2;
        
    int L[n1], R[n2]; count += 2;
        
    for (int i = 0; i < n1; i++) {
      count++;
      L[i] = arr[left + i];
      count++;
    }
    count++;
        
    for (int j = 0; j < n2; j++) {
      count++;
      R[j] = arr[mid + 1 + j];
      count++;
    }
    count++;
        
    int i = 0, j = 0, k = left;
    count += 3;
        
    while (i < n1 && j < n2) {
      count++;
      if (L[i] <= R[j]) {
	count++;
	arr[k] = L[i]; count++;
	i++; count++;
      } else {
	count++;
	arr[k] = R[j]; count++;
	j++; count++;
      }
      k++;
      count++;
    }
    count++;
        
    while (i < n1) {
      count++;
      arr[k] = L[i]; count++;
      i++; count++;
      k++; count++;
    }
    count++;
        
    while (j < n2) {
      count++;
      arr[k] = R[j]; count++;
      j++; count++;
      k++; count++;
    }
    count++;
  }
    
  int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    count += 2;
    int i = low - 1;
    count++;
        
    for (int j = low; j < high; j++) {
      count++;
      if (arr[j] <= pivot) {
	count++;
	i++;
	count++;
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	count += 3;
      }
    }
    count++;
        
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    count += 3;
        
    return i + 1;
  }
    
  void heapify(int arr[], int n, int i) {
    int largest = i;
    count++;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    count += 2;
        
    if (left < n && arr[left] > arr[largest]) {
      count++;
      largest = left;
      count++;
    }
    count++;
        
    if (right < n && arr[right] > arr[largest]) {
      count++;
      largest = right;
      count++;
    }
    count++;
        
    if (largest != i) {
      count++;
      int temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;
      count += 3;
      heapify(arr, n, largest);
    }
  }
    
public:
  DivideConquer() : count(0) {}

  void getCount() {cout << "Imperative analysis: " << count << endl;}
  void resetCount() {count = 0;}
  
  void displayArr(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
      cout << " " << arr[i];
      if (i < size - 1) {
	cout << ",";
      }
    }
    cout << " ]";
  }
  
  int binarySearch(int arr[], int left, int right, int key) {
    count++;
    if (right < left) {
      count++;
      return -1;
    }
        
    int mid = left + (right - left) / 2;
    count += 4;
        
    if (arr[mid] == key) {
      count++;
      return mid;
    }
        
    if (arr[mid] < key) {
      count++;
      return binarySearch(arr, mid + 1, right, key);
    } else {
      count++;
      return binarySearch(arr, left, mid - 1, key);
    }
  }
    
  MinMaxRes minMax(int arr[], int left, int right) {
    count++;
    MinMaxRes result;
        
    if (left == right) {
      count++;
      result.min = arr[left];
      result.max = arr[left];
      count += 2;
      return result;
    }
        
    if (left + 1 == right) {
      count++;
      if (arr[left] < arr[right]) {
	count++;
	result.min = arr[left];
	result.max = arr[right];
	count += 2;
      } else {
	count++;
	result.min = arr[right];
	result.max = arr[left];
	count += 2;
      }
      return result;
    }
        
    int mid = left + (right - left) / 2;
    count += 4;
        
    MinMaxRes leftRes = minMax(arr, left, mid);
    MinMaxRes rightRes = minMax(arr, mid + 1, right);
    count += 2;
        
    if (leftRes.min < rightRes.min) {
      result.min = leftRes.min;
      count++;
    } else {
      result.min = rightRes.min;
      count++;
    }
        
    if (leftRes.max > rightRes.max) {
      result.max = leftRes.max;
      count++;
    } else {
      result.max = rightRes.max;
      count++;
    }
        
    return result;
  }
    
  void mergeSort(int arr[], int left, int right) {
    count++;
    if (left < right) {
      count++;
      int mid = left + (right - left) / 2;
      count += 4;
            
      mergeSort(arr, left, mid);
      mergeSort(arr, mid + 1, right);
      count += 2;
            
      merge(arr, left, mid, right);
    }
  }
    
  void quickSort(int arr[], int low, int high) {
    count++;
    if (low < high) {
      count++;
      int pi = partition(arr, low, high);
      count++;
            
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
      count += 2;
    }
  }
    
  void heapSort(int arr[], int n) {
    count++;
    for (int i = n / 2 - 1; i >= 0; i--) {
      count++;
      heapify(arr, n, i);
    }
    count++;
        
    for (int i = n - 1; i > 0; i--) {
      count++;
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      count += 3;
            
      heapify(arr, i, 0);
    }
    count++;
  }
};

#endif
