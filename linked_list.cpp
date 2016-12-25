#include <iostream>
#include <cstdlib>
#include <cmath>

class Node {
  public:
    Node(int v, Node* n) : val(v), next(n) {}
    int val;
    Node* next;
};

void print(Node* node) {
  if(node == NULL) return;
  std::cout << node->val << std::endl;
  print(node->next);
}

Node* insert(Node* node, int val) {
  if( (node == NULL) || (node->val > val) ) 
    return new Node(val, node);
  node->next = insert(node->next, val);
  return node;
}

Node* remove(Node* node, int val) {
  if(node->val == val) {
    Node *temp = node->next;
    delete node;
    return temp;
  }
  node->next = remove(node->next, val);
  return node;
}

int size(Node * node) {
  if(node == NULL) return 0;
  return 1 + size(node->next);
}

int main() {
  Node* ll = NULL;
  int testRem;
  int arr[] = {3,6,7,5,1};
  for(int i = 0 ; i < 5 ; i++) {
    ll = insert(ll, arr[i]);
  }
  testRem = arr[3];
  std::cout << "Inserted elements: \n";
  print(ll);
  
  remove(ll, testRem);
  
  std::cout << "After removing " << testRem  << ":" << std::endl;
  print (ll);

  std::cout << "Size of LL: " << size(ll) << std::endl;
  return 0;
}
