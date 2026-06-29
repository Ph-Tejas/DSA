/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* prev=new Node(-1000);



        queue<pair<Node*,int>>q;
        q.push({root,0});
        int ct=-1;
        while(!q.empty()){
            Node* node=q.front().first;
            int lvl=q.front().second;
            q.pop();
            if(node==NULL)continue;
            if(ct==lvl){
                prev->next=node;
                prev=node;

            }
            else{
                ct=lvl;
                prev=node;
            }
            if(node->left!=NULL){
                q.push({node->left,lvl+1});
            }
            if(node->right!=NULL){
                q.push({node->right,lvl+1});
            }


        }
        return root;
        
    }
};