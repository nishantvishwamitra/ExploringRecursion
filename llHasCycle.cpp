#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <list>
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
private:
  bool delegate(ListNode* slow, ListNode* fast) {
    if(slow == NULL || fast == NULL) return false;
    if(slow == fast) return true;
    if(fast->next == NULL) return false;
    if(delegate(slow->next, fast->next->next) == false) return false;
    return true;
  }
public:
  bool hasCycle(ListNode *head) {
    if(head == NULL) return false;
    if(head->next == NULL) return false;
    return delegate(head, head->next->next);
  }
};

int main() {
  Solution s;
  int a [] = {1,2,4,5,7,9};
  ListNode* l1 = new ListNode(a[0]);
  ListNode* temp = l1;
  ListNode* cycleto = NULL;
  for(int i = 1 ; i < 6 ; ++i) {
    l1->next = new ListNode(a[i]);
    l1 = l1->next;
    if(i == 2) cycleto = l1;
  }
  l1->next = cycleto;
  std::cout << s.hasCycle(temp) << std::endl;
  return 0;
}
