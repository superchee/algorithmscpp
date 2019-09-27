#include <cstddef>
#include <vector>

using namespace std;


/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return !l1? l2:l1;
        ListNode *head = NULL, *cur = NULL;

        if (l1->val <= l2->val){
            head = cur = l1;
            l1 = l1->next;
        }else{
            head = cur = l2;
            l2 = l2->next;
        }

        while (l1 && l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }else{
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }

        if (l1){
            cur->next = l1;
        }else{
            cur->next = l2;
        }

        return head;
    }
    ListNode* mergeSplit(vector<ListNode*>& lists, int start, int end){
        if (start == end) return lists[start];

        ListNode *l1 = NULL, *l2 = NULL;
        int mid = start + (end-start)/2;

        l1 = mergeSplit(lists, start, mid);
        l2 = mergeSplit(lists, mid+1, end);

        return mergeTwoLists(l1, l2);


    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        return mergeSplit(lists, 0, lists.size()-1);
    }
};