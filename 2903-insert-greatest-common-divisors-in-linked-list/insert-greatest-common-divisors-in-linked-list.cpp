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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* st=head;
        if(head->next==NULL)return head;
        ListNode* en=head->next;
        while(en!=NULL){
            st->next=new ListNode(gcd(st->val,en->val));
            st->next->next=en;
            st=en;
            en=en->next;
        }
        return head;
        
        
    }
};