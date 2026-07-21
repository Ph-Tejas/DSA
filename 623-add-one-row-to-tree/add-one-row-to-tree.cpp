/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dep,v;
    void fun(TreeNode* root,int d){
        if(root==NULL)return;
        if(d==dep-1){

            TreeNode* l=root->left;
            TreeNode* r=root->right;
            root->left=new TreeNode(v);
            root->right=new TreeNode(v);
            root->left->left=l;
            root->right->right=r;
            return;


        }
        if(root->left!=NULL)fun(root->left,d+1);
        if(root->right!=NULL)fun(root->right,d+1);

        
        
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        dep=depth;
        v=val;
        if(dep==1){
            TreeNode* n=new TreeNode(val);
            n->left=root;
            return n;
        }
        fun(root,1);  
        return root;  
    }
};