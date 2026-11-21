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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // if(!head->next){
        //     return nullptr;
        // }

        int size=0;
        ListNode* ptr= head, *prev = nullptr;
        while(ptr){
            size++;
            ptr = ptr->next;
        };
        n= size -n;
        size = 0;
        ptr = head;
        while(ptr){
            if(n==size){
                if(n==0){
                    head = head->next;
                    break;
                }
                prev->next= ptr->next;
                ptr->next= nullptr;
                break;
            }
            size++;
            prev = ptr;
            ptr= ptr->next;
        }

        return head;

    }
};
