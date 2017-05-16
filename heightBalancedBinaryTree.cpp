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
  int delegate(TreeNode* root, int depth) {
    if(root == NULL) return depth;
    ++depth;
    int l = delegate(root->left, depth);
    int r = delegate(root->right, depth);
    return (l > r ? l : r);
  }
public:
  bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    int l = delegate(root->left, 0);
    int r = delegate(root->right, 0);
    //std::cout << l << " " << r << std::endl;
    if( abs(l - r) > 1 ) return false;
    return (isBalanced(root->left) && isBalanced(root->right));
  }
};

int main() {
  Solution s;
  
  TreeNode *one1 = new TreeNode(1);
  TreeNode *two1 = new TreeNode(2);
  TreeNode *three1 = new TreeNode(3);
  TreeNode *four1 = new TreeNode(4);
  TreeNode *five1 = new TreeNode(5);
  TreeNode *six1 = new TreeNode(6);

  one1->left = two1;
  one1->right = three1;
  two1->left = four1;
  two1->right = five1;
  //five1->left = six1;
  
  
  /*
  TreeNode* one = new TreeNode(1);
  TreeNode* two1 = new TreeNode(2);
  TreeNode* two2 = new TreeNode(2);
  TreeNode* three1 = new TreeNode(3);
  TreeNode* three2 = new TreeNode(3);
  TreeNode* four1 = new TreeNode(4);
  TreeNode* four2 = new TreeNode(4);

  one->left = two1;
  one->right = two2;
  two1->left = three1;
  two2->right = three2;
  three1->left = four1;
  three2->right = four2;
  */
 
  std::cout << s.isBalanced(one1) << std::endl;
  return 0;
}
