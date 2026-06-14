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
    int pairSum(ListNode* head) {
        l st=head;
        int ct=1;
        l en=head->next;
        while(en->next!=NULL){
            st=st->next;
            en=en->next->next;
            ct++;
        }
        en=st->next;
        l a;
        l b;
        l c;
        if(ct==1){
            st->next=NULL;
        }
        else if(ct==2){
            st->next=head;
            head->next=NULL;
        }
        else{
            a=head;
            b=head->next;
            c=b->next;
            a->next=NULL;
            while(c!=st){
                b->next=a;
                a=b;
                b=c;
                c=c->next;
            }
            b->next=a;
            c->next=b;


        }
        int maxi=0;
        while(st!=NULL){
            maxi=max(maxi,(st->val)+(en->val));
            st=st->next;
            en=en->next;
        }
        return maxi;
    }
};