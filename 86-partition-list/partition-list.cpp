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
    ListNode* partition(ListNode* head, int x) {
        ListNode* a=new ListNode(-1000);
        ListNode* b=new ListNode(-1000);
        ListNode* st_a=new ListNode(-1000);
        ListNode* st_b=new ListNode(-1000);

        while(head!=NULL){
            if(head->val<x){
                if(a->val==-1000){
                    a=head;
                    st_a=head;
                    head=head->next;
                    a->next=NULL;
                }
                else{
                    a->next=head;
                    head=head->next;
                    a->next->next=NULL;
                    a=a->next;
                }
            }
            else {
                if(b->val==-1000){
                    b=head;

                    st_b=head;
                    head=head->next;
                    b->next=NULL;
                }
                else{
                    b->next=head;
                    head=head->next;
                    b->next->next=NULL;
                    b=b->next;
                }
            }
            
            
        
        }
        if(a->val!=-1000){
            if(b->val!=-1000){
                a->next=st_b;
            }
            return st_a;
            
        }
        else if(b->val!=-1000){
            
            return st_b;

        }
        return NULL;

        
    }
};