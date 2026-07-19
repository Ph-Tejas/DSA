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
    int ans=0;
    int check(TreeNode* root){
        int flag=false;
        int maxi=root->val;
        if(root->left!=NULL){
            int a=check(root->left);
            maxi=max(maxi,a);
            if(root->val<a)flag=true;
        }
        if(root->right!=NULL){
            int a=check(root->right);
            maxi=max(maxi,a);
            if(root->val<a)flag=true;
        }
        if(!flag)ans++;
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        check(root);
        return ans;
        
    }
};