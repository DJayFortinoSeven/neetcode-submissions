/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode *t1,*start;
    void recurr(ListNode *last){
        
        if(last == nullptr){
            return;
        }
        recurr(last->next);
        
        if (start == nullptr) {
            return;
        }

        if (start == last || start->next == last) {
            last->next = nullptr;
            start = nullptr;
            return;
        }
        
        t1 = start->next;
        start->next = last;
        start = start->next;
        start->next = t1;
        start = start->next;

        return;
    }
    void reorderList(ListNode* head) {
        start = head;
        recurr(head->next);
        return;
    }
};
