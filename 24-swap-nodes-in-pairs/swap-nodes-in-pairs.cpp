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
    ListNode* swapPairs(ListNode* head) {
        ListNode* node=head;
        ListNode* nxt;
        bool flag=false;
        ListNode* prev=new ListNode(-1);
        while(node!=NULL&&node->next!=NULL){
            nxt=node->next->next;
            if(!flag){
                flag=true;
                head=node->next;
            }
            node->next->next=node;
            node->next=nxt;
            prev=node;
            node=nxt;
            if(prev->next!=NULL&&prev->next->next!=NULL){
                prev->next=prev->next->next;
            }


            
        }
        return head;
    }
};