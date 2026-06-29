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
#define ll  TreeNode*
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>>ans;
        queue<pair<ll,int>>q;
        vector<int>sample;
        q.push({root,0});
        int ct=0;
        while(!q.empty()){
            ll node=q.front().first;
            int lvl=q.front().second;
            q.pop();
            if(ct!=lvl){
                ct=lvl;
                ans.push_back(sample);
                sample.clear();
            }

            sample.push_back(node->val);
            if(node->left!=NULL){
                q.push({node->left,lvl+1});
            }
            if(node->right!=NULL){
                q.push({node->right,lvl+1});
            }

            

        }
        ans.push_back(sample);
        for(int i=0;i<ans.size();i++){
            if(i&1){
                reverse(ans[i].begin(),ans[i].end());
            }
        }




        return ans;
    }
};