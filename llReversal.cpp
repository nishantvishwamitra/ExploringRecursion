#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <cmath>
#include <stack>


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rev(ListNode* left, ListNode* curr) {
  if(curr == NULL) return left;
  ListNode* right = curr->next;
  curr->next = left;
  rev(curr, right);
}

int main() {
  ListNode* l1 = new ListNode(1);
  ListNode* h1 = l1;
  for(int i = 2 ; i <= 4 ; ++i) {
    l1->next = new ListNode(i);
    l1 = l1->next;
  }
  h1 = rev(NULL, h1);
  while(h1 != NULL) {
    std::cout << h1->val << std::endl;
    h1 = h1->next;
  }
  return 0;
}
