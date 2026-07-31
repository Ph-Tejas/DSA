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
    int it=0;
    int dp[10001][2];
    TreeNode* dfs(TreeNode* node){
        TreeNode* toBeReturned=new TreeNode(it);
        TreeNode* l=NULL;
        TreeNode* r=NULL;
        if(node->left!=NULL){
            it++;
            l=dfs(node->left);
        }
        if(node->right!=NULL){
            it++;
            r=dfs(node->right);
        }
        toBeReturned->left=l;
        toBeReturned->right=r;
        return toBeReturned;
        
    }
    int fun(TreeNode* ind,TreeNode* node,int take){
        int id=ind->val;
        if(dp[id][take]!=-1)return dp[id][take];
        int ans=0;
        if(take==0){
            if(node->left!=NULL){
                ans+=max(fun(ind->left,node->left,0),fun(ind->left,node->left,1));
            }
            if(node->right!=NULL){
                ans+=max(fun(ind->right,node->right,0),fun(ind->right,node->right,1));
            }
        }
        else{
            ans+=node->val;
            if(node->left!=NULL){
                ans+=fun(ind->left,node->left,0);
            }
            if(node->right!=NULL){
                ans+=fun(ind->right,node->right,0);
            }

        }
        return dp[id][take]=ans;

    }
    int rob(TreeNode* root) {
        TreeNode* ind=dfs(root);
        memset(dp,-1,sizeof(dp));

        return max(fun(ind,root,0),fun(ind,root,1));
    }
};