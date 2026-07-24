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
    int maxi=0;
    int fun(TreeNode* node){
        int l=0;
        int r=0;
        if(node->left!=NULL){
            int a=fun(node->left);
            if(node->val==node->left->val)l=a;
            
        }
        if(node->right!=NULL){
            int a=fun(node->right);
            if(node->val==node->right->val)r=a;
        }
        maxi=max(maxi,1+l+r);
        return 1+(max(l,r));


    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)return 0;
        fun(root);     
        return maxi-1;
    }
};