#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>
#include <stack>

int result;

bool isPrime(int n) {
  int i;
  for(i = 2; i < n; ++i) {
    if (n % i == 0 && i != n) return false;
  }
  return true;
}

void nthFibPrime(int fir, int sec, int n) {
  if(n == 0) return;
  int next = fir + sec;
  if(isPrime(next)) {
    result = next;
    --n;
    nthFibPrime(sec, next, n);
  } else {
    nthFibPrime(sec, next, n);
  }
}

int main() {
  nthFibPrime(1, 1, 9);
  std::cout << result << std::endl; 
  return 0;
}
