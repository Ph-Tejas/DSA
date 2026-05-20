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
    
    int t;
    
    int ans=0;
    vector<long long> postOrder(TreeNode* node){
        if(node==NULL)return {};
        vector<long long>l=postOrder(node->left);
        vector<long long>r=postOrder(node->right);
        vector<long long>v;
        v.push_back(node->val);
        if(node->val==t)ans++;
        for(int i=0;i<l.size();i++){
            if((long long)node->val+l[i]==t)ans++;
            v.push_back((long long)node->val+l[i]);
        }
        for(int i=0;i<r.size();i++){
            if((long long)node->val+r[i]==t)ans++;
            v.push_back((long long)node->val+r[i]);
        }
        return v;
        

    }
    int pathSum(TreeNode* root, int targetSum) {
        t=targetSum;
        postOrder(root);
        return ans;

        
    }
};