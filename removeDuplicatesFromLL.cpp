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

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
 
  void worker(ListNode* head, ListNode* prev, ListNode* res) {
    if(head != NULL) {
      if(prev != NULL && prev->val != head->val) {
        res->next = new ListNode(head->val);
        worker(head->next, head, res->next);
      } else {
        if(prev == NULL) {  
          res->next = new ListNode(head->val);
          worker(head->next, head, res->next);
        } else
          worker(head->next, head, res);
      }
    }
  }

  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = new ListNode(0);// Dummy placeholder
    ListNode* prev = NULL;
    ListNode* temp = res;
    worker(head, prev, res);
    return temp->next;
  }
};

int main() {
  Solution s;
  int a [] = {1,1,2,3,3,3,3,3,3,3,3,4};
  ListNode* l1 = new ListNode(a[0]);
  ListNode* temp = l1;
  for(int i = 1 ; i < 12 ; ++i) {
    l1->next = new ListNode(a[i]);
    l1 = l1->next;
  }
  ListNode* h1 = s.deleteDuplicates(temp);
  while(h1 != NULL) {
    std::cout << h1->val << std::endl;
    h1 = h1->next;
  } 
  return 0;
}
