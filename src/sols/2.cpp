#include <vector>
#include <map>
#include "objs/listnode.h"
using namespace std;

class Solution{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode *l2) {
            ListNode* head = new ListNode(0);
            ListNode* tmp = head;
            int carry = 0;
            while (l1 || l2 || carry) {
                int current = 0;
                if (l1) {
                    current += l1->val;
                    l1 = l1->next;
                }
                if (l2) {
                    current += l2->val;
                    l2 = l2->next;
                }
                if (carry) {
                    current += carry;
                }

                tmp->next = new ListNode(current%10);
                tmp = tmp->next;
                carry = current / 10;
            }
            return head->next;
        }
};