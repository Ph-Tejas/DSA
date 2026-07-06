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
    int findLoc(int i,int j,vector<int>&nums){
        int maxi=-1;
        int ind=0;
        for(int it=i;it<=j;it++){
            if(maxi<nums[it]){
                maxi=nums[it];
                ind=it;
            }
        }
        return ind;
    }
    TreeNode* build(vector<int>& nums,int i,int j){
        if(j<i)return NULL;
        int ind= findLoc(i,j,nums);
        TreeNode* node=new TreeNode(nums[ind]);
        node->left=build(nums,i,ind-1);
        node->right=build(nums,ind+1,j);
        return node;







    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return build(nums,0,n-1);

    }
};