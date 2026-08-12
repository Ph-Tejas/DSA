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
    vector<int>v;
    
    vector<TreeNode*> build(int i,int j){
        if(i>j){
            return {NULL};
        }
        if(i==j){
            TreeNode* root=new TreeNode(v[i]);
            return {root};
        }
        vector<TreeNode*>ans;

        for(int it=i;it<=j;it++){
            vector<TreeNode*>l=build(i,it-1);
            vector<TreeNode*>r=build(it+1,j);
            for(auto &l1:l){
                for(auto &r1:r){
                    TreeNode* node=new TreeNode(v[it]);
                    node->left=l1;
                    node->right=r1;
                    ans.push_back(node);
                }
            }

            

        }
        return ans;




    }
    vector<TreeNode*> generateTrees(int n) {
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }

        
        return build(0,n-1);
       
    }
};