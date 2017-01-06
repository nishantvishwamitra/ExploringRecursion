#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>

// Balanced Parenthises using recursion and not using Stack :). Worse time complexity than with stack but it works. Maybe useful
// you cant use stack.

bool isValid(std::string s) {
  bool done = false;
  std::string::iterator it = s.begin();
  while(it != s.end()) {
    if( (it != s.end() - 1) && (*it == '(' && *(it + 1) == ')') || (*it == '{' && *(it + 1) == '}') || (*it == '[' && *(it + 1) == ']')) {
      done = true;
      it = s.erase(it);
      it = s.erase(it);
    } else
      ++it;
  }
  // std::cout << "string: " << s <<std::endl;
  if(!s.empty()) {
    if(done) {
      return isValid(s);
    } else {
      return false;
    } 
  } else {
    return true;
  }
}

class Solution {
public:
  bool isValid(std::string s) {
     return ::isValid(s);
  }
};

int main() {
  Solution s;
  std::string str = "(){[]}";
  //str = "(()(";
  //str = "()";
  str = "(()())";
  std::cout << s.isValid(str) << std::endl; 
  return 0;
}
