#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
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
  bool validate(TreeNode* node1, TreeNode* node2) {
    //if(node1 != NULL && node2 != NULL)  
      //std::cout << node1->val << " " << node2->val << std::endl;
    if(node1 == NULL && node2 == NULL) {
      return true;
    } else if(node1 != NULL && node2 == NULL) {
      return false;
    } else if(node1 == NULL && node2 != NULL) {
      return false;
    } else {
      if(!validate(node1->left, node2->left)) return false;
      if(node1->val != node2->val) return false;
      if(!validate(node1->right, node2->right)) return false;
    }
    return true;
  }

public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    return validate(p, q);
  }
};

int main() {
  Solution s;
  TreeNode *one1 = new TreeNode(1);
  TreeNode *two1 = new TreeNode(2);
  TreeNode *three1 = new TreeNode(3);
  TreeNode *four1 = new TreeNode(4);
  TreeNode *five1 = new TreeNode(5);
 
  TreeNode *one2 = new TreeNode(1);
  TreeNode *two2 = new TreeNode(2);
  TreeNode *three2 = new TreeNode(3);
  TreeNode *four2 = new TreeNode(4);
  TreeNode *five2 = new TreeNode(5);

  one1->left = two1;
  one1->right = three1;
  two1->left = four1;
  two1->right = five1;
  
  one2->left = two2;
  one2->right = three2;
  two2->left = four2;
  two2->right = five2;
 
  std::cout << s.isSameTree(one1, one2) << std::endl; 
  return 0;
}
