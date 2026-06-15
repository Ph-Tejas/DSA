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
#define l ListNode*
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        l slow=head;
        l fast=head->next;
        if(head->next==NULL){
            return NULL;
        }
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        l temp=slow->next;

        slow->next=slow->next->next;
        temp->next=NULL;
        return head;
    }
};