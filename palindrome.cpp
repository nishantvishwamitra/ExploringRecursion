#include <iostream>
#include <cstdlib>

bool isPal(char* arr, int beg, int end) {
  if(arr[beg] != arr[end]) return false;
  if(beg == end) return true;
  return true && isPal(arr, beg + 1, end - 1);
}

int main() {
  int size = 5;
  char arr[] = {'m','a','d','a','m'};
  int beg = 0;
  int end = size - 1;
  bool res = isPal(arr, beg, end);
  std::cout << "Result: " << res << std::endl;
  return 0;
}
