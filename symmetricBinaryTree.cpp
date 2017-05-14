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
bool isEqual(TreeNode* root1, TreeNode* root2) { 
  bool temp = false;
  if(root1 == NULL && root2 == NULL) {
    return true;
  } else if(root1 == NULL && root2 != NULL) {
    return false;
  } else if(root1 != NULL && root2 == NULL) {
    return false;
  } else if(root1->val == root2->val) {
    return isEqual(root1->left, root2->right) && isEqual(root1->right, root2->left);
  } else {
    return false;
  }
}
public:
  bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return isEqual(root->left, root->right);
  }
};

int main() {
  Solution s;
  
  TreeNode *one = new TreeNode(1);
  TreeNode *two1 = new TreeNode(2);
  TreeNode *two2 = new TreeNode(2);
  TreeNode *three1 = new TreeNode(3);
  TreeNode *three2 = new TreeNode(3);
 
  one->left = two1;
  one->right = three1;
  two1->left = three2;
  three1->left = two2;
  
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
  std::cout << s.isSymmetric(one) << std::endl; 
  return 0;
}
 
