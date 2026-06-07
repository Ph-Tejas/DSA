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
    TreeNode* createBinaryTree(vector<vector<int>>& description) {
        int n=description.size();
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            int curr=description[i][1];
            mp[curr]=new TreeNode(curr);
            mp[description[i][0]]=new TreeNode(description[i][0]);
            st.insert(curr);
            st.insert(description[i][0]);
        }for(int i=0;i<n;i++){
            int curr=description[i][1];

            if(st.find(curr)!=st.end())st.erase(curr);
            if(description[i][2]==0)mp[description[i][0]]->right=mp[curr];
            else mp[description[i][0]]->left=mp[curr];
        }
        auto it=st.begin();
        return mp[(*it)];
        

    }
};