#include <iostream>
//#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int compute(TreeNode* root, int depth) {
    int l = 0;
    int r = 0;
    if(root == NULL)
      return depth;
    depth = depth + 1;
    l = compute(root->left, depth); 
    r = compute(root->right, depth);
    return (l > r ? l : r);
  }

public:
  int maxDepth(TreeNode* root) {
    int depth;
    depth = 0;
    return compute(root, depth);
  }
};

int main() {
  Solution s;
  
  TreeNode *one = new TreeNode(1);
  TreeNode *two1 = new TreeNode(2);
  TreeNode *two2 = new TreeNode(2);
  TreeNode *three1 = new TreeNode(3);
  TreeNode *three2 = new TreeNode(3);
  TreeNode *four1 = new TreeNode(4);
 
  one->left = two1;
  one->right = three1;
  two1->left = three2;
  three1->left = two2;
  three2->left = four1;
  
  /*
  TreeNode *one1 = new TreeNode(1);
  TreeNode *two1 = new TreeNode(2);
  TreeNode *two2 = new TreeNode(2);
  TreeNode *three1 = new TreeNode(3);
  TreeNode *four1 = new TreeNode(4);
  TreeNode *three2 = new TreeNode(3);
  TreeNode *four2 = new TreeNode(4);

  one1->left = two1;
  one1->right = two2;
  two1->left = three1;
  two1->right = four1;
  two2->left = four2;
  two2->right = three2;
  */
  std::cout << s.maxDepth(one) << std::endl; 
  return 0;
}
