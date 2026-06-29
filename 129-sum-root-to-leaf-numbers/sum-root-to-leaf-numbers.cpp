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
    int sum=0;
    void fun(TreeNode* root,string& s){
        if(root->left==NULL&&root->right==NULL){
            sum+=stoi(s);
            return;

        }
        if(root->left!=NULL){
            s+=to_string(root->left->val);

            fun(root->left,s);
            
            s.pop_back();
            
        }
        if(root->right!=NULL){

            s+=to_string(root->right->val);
            
            fun(root->right,s);
            s.pop_back();
        }
    
        
    }
    int sumNumbers(TreeNode* root) {
        string s=to_string(root->val);
        
        fun(root,s);
        return sum;
    }
};