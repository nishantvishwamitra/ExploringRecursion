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
    if(root == NULL) return depth;
    ++depth;
    int l = compute(root->left, depth); 
    int r = compute(root->right, depth);
    //std::cout << l << " " << r << std::endl;
    if(root->left == NULL && root->right != NULL) return r;
    if(root->left != NULL && root->right == NULL) return l;
    return (l < r ? l : r);
  }

public:
  int minDepth(TreeNode* root) {
    if(root == NULL) return 0;
    return compute(root, 0);
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
 
  std::cout << s.minDepth(one) << std::endl;
  return 0;
}
