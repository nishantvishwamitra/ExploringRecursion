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
  bool delegate(TreeNode* root, int sum, int pathSum) {
    if(root == NULL) return false;
    int thisSum = root->val + pathSum;
    if(root->left == NULL && root->right == NULL && sum == thisSum) return true; 
    if( delegate(root->left, sum, thisSum) ) return true;
    if( delegate(root->right, sum, thisSum) ) return true;
    return false;
  }
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if(root == NULL) return false;
    return delegate(root, sum, 0);
  }
};

int main() {
  Solution s;
  
  TreeNode *five = new TreeNode(5);
  TreeNode *four1 = new TreeNode(4);
  TreeNode *eight = new TreeNode(8);
  TreeNode *eleven = new TreeNode(11);
  TreeNode *seven = new TreeNode(7);
  TreeNode *two = new TreeNode(2);
  TreeNode *thirteen = new TreeNode(13);
  TreeNode *four2 = new TreeNode(4);
  TreeNode *one = new TreeNode(1);

  five->left = four1; 
  five->right = eight;
  four1->left = eleven;
  eleven->left = seven; 
  eleven->right = two;
  eight->left = thirteen; 
  eight->right = four2;
  four2->right = one; 
 
  std::cout << s.hasPathSum(five, 22) << std::endl;
  return 0;
}
