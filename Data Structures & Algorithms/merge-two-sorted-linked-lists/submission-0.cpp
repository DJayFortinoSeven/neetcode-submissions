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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }

        ListNode *head, *prev, *temp ;
        if(list1->val <= list2->val){
            head = list1;
        }
        else{
            head = list2;
        }
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val){
                prev = list1;
                list1 = list1->next;
            }
            else{
                temp = list2->next;
                list2->next = list1;
                prev->next = list2;
                prev = list2;
                list2 = temp;
            }
        }
        if(list1 == nullptr && list2 != nullptr){
            prev->next = list2;
        }
        return head;
    }
};
