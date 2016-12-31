#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>

// LCP Algorithm using Recursion and Divide & Conquer 

std::string getLcp(std::vector<std::string>& strs, int l, int h) {
  std::string lcpF = "";
  std::string lcpS = "";
  std::string lcp = "";
  int m;
  m = (l + h) / 2;
  if(l < h) {
    lcpF = getLcp(strs, l, m);
    lcpS = getLcp(strs, m + 1, h);
    
    std::string::iterator itF = lcpF.begin();
    std::string::iterator itS = lcpS.begin();
    while(itF != lcpF.end() || itS != lcpS.end()) {
      if(*itF == *itS) {
        lcp = lcp + *itF;
      } else
        break;
      ++itF;
      ++itS;
    }
    return lcp;
  } 
  return strs[m]; 
}

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if(strs.size() == 0) return "";
    return getLcp(strs, 0, strs.size() - 1);
  }
};

int main() {
  Solution s;
  std::vector<std::string> strs;
  strs.push_back("aabb");
  strs.push_back("aab");
  strs.push_back("aa");
  strs.push_back("aaa");
  std::cout << s.longestCommonPrefix(strs) << std::endl;
  return 0;
}
