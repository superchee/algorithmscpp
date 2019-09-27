#include <cstddef>
#include <new>


/* *
 * Definition for singly-linked list.
 * */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l = NULL, *r = NULL, *pre = NULL;

        l = r = head;

        while(r && n--){
            r = r->next;
        }

        if (r == NULL){
            head = head->next;
            delete l;
            return head;
        }

        while(r){
            pre = l;
            r = r->next;
            l = l->next;
        }

        pre->next = pre->next->next;
        delete l;
        return head;

    }
};