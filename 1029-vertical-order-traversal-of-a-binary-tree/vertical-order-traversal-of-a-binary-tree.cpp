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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<pair<int,int>,TreeNode*>>q;
        q.push({{0,0},root});
        vector<pair<pair<int,int>,int>>v;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            TreeNode* node=q.front().second;
            q.pop();
            v.push_back({{x,y},node->val});
            if(node->left!=NULL){
                q.push({{x-1,y+1},node->left});
            }
            if(node->right!=NULL){
                q.push({{x+1,y+1},node->right});
            }
        }
        sort(v.begin(),v.end());
        int ct=INT_MIN;
        int n=v.size();
        vector<vector<int>>ans;
        vector<int>v1;
        for(int i=0;i<n;i++){

            if(v[i].first.first!=ct){
                if(ct==INT_MIN){
                    v1.push_back(v[i].second);
                }
                else{
                    ans.push_back(v1);
                    v1.clear();
                    v1.push_back(v[i].second);
                }
                ct=v[i].first.first;

            }
            else{
                v1.push_back(v[i].second);
            }
        }
        ans.push_back(v1);
        return ans;











    }
};