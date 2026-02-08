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
    bool ans=true; 
    int fun(TreeNode* root){
        if(!ans)return 0;
        if(root==NULL)return 0;
        int a=fun(root->left);
        int b=fun(root->right);
        if(abs(a-b)>1){
            ans=false;
        }
        if(a<b)return b+1;
        else return a+1;
    }
    bool isBalanced(TreeNode* root) {
        fun(root);
        return ans;
    }
};