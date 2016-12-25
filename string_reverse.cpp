#include <iostream>
#include <cstdlib>

void rev(int* arr, int beg, int end) {
  if(beg == end) return;
  int temp = arr[beg];
  arr[beg] = arr[end];
  arr[end] = temp;
  if(beg + 1 == end) return;
  rev(arr, beg + 1, end - 1);
}

void print(int *arr, int size) {
  for(int i = 0 ; i < size ; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int size = 5;
  int arr[] = {1,2,3,4,5};
  int beg = 0;
  int end = size - 1;
  std::cout << "Before: " << std::endl;
  print(arr, size);
  rev(arr, beg, end);
  std::cout << "After: " << std::endl;
  print(arr, size);
  return 0;
}
