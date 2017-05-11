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

void print(TreeNode* node, int method) {
  if(node == NULL) {
    return;
  }

  switch(method) {
    case 1: //Inorder
      print(node->left, 1);
      std::cout << node->val << " " ;
      print(node->right, 1);
    break;
    case 2: //Preorder
      std::cout << node->val << " " ;
      print(node->left, 2);
      print(node->right, 2);
    break;
    case 3:// Postorder
      print(node->left, 3);
      print(node->right, 3);
      std::cout << node->val << " " ;
    break;
  }
}

int main() {
  TreeNode *one = new TreeNode(1);
  TreeNode *two = new TreeNode(2);
  TreeNode *three = new TreeNode(3);
  TreeNode *four = new TreeNode(4);
  TreeNode *five = new TreeNode(5);
  TreeNode *six = new TreeNode(6);
  TreeNode *seven = new TreeNode(7);
  TreeNode *eight = new TreeNode(8);
  TreeNode *nine = new TreeNode(9);
  
  one->left = two;
  one->right = three;
  two->left = four;
  two->right = five;
  three->left = six;
  three->right = seven;
  four->left = eight;
  seven->right = nine;

  std::cout << "Inorder (L,V,R)" << std::endl;
  print(one, 1);
  std::cout << std::endl;
 
  std::cout << "Preorder (V,L,R)" << std::endl;
  print(one, 2);
  std::cout << std::endl;

  std::cout << "Postorder (L,R,V)" << std::endl;
  print(one, 3);
  std::cout << std::endl;
  return 0;
}
