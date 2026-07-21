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
    int ans=INT_MIN;
    vector<pair<int,int>>dp;
    pair<int,int>ref={-1,-1};
    pair<int,int> fun(TreeNode* root,int &i){
        
        if(dp[i]!=ref){
            return dp[i];
        }
        int mini=root->val;
        int maxi=root->val;
        if(root->left!=NULL){
            i++;
            mini=min(fun(root->left,i).first,mini);
            maxi=max(fun(root->left,i).second,maxi);
        }
        if(root->right!=NULL){
            i++;
            mini=min(fun(root->right,i).first,mini);
            maxi=max(fun(root->right,i).second,maxi);
        }

        ans=max(ans,max(abs(root->val-mini),abs(root->val-maxi)));
        
        return dp[i]={mini,maxi};
    }
    int maxAncestorDiff(TreeNode* root) {
        dp.resize(10000,ref);
        int i=0;
        pair<int,int>pr=fun(root,i);
        for(int i=0;i<100;i++){
            cout<<dp[i].first<<" "<<dp[i].second<<endl;
        }
        
        return ans;

    }
};