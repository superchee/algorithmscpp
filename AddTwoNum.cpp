#include <cstddef>


//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carray = 0, sum = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        while(l1 || l2 || carray){
            sum = carray;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            carray = sum/10;

            current->next = new ListNode(sum%10);
            current = current->next;

        }
        return dummy->next;
    }
};