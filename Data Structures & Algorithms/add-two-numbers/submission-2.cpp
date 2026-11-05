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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans= l1,*prev;
        while(l1 && l2){
            l1->val += l2->val;
            l1->val += carry;
            carry = (l1->val)/10;
            l1->val %= 10;

            prev = l1;
            l1= l1->next;
            l2= l2->next;
        }
        if(l2){
            prev->next = l2;
            // l2->val += carry;
            l1 = l2;
            l2 = nullptr;
        }
        while(l1){
            l1->val += carry;
            carry = (l1->val)/10;
            l1->val %= 10;
            prev = l1;
            l1 = l1->next;
        }
        if(!l1 && !l2 && carry>0){
            ListNode *x = new ListNode(carry);
            prev->next = x;
        }

        return ans;
    }
};
