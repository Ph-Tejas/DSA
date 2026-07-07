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
    int n;
    TreeNode* fun(string &traversal,int lvl,int &idx){
        string num;
        while(idx<n && traversal[idx]!='-'){
            num.push_back(traversal[idx]);
            idx++;

        }   
        int value=stoi(num);
        TreeNode* node=new TreeNode(value);
        if(idx==n)return node;
        
        int ct=0;
        while(idx<n && traversal[idx]=='-'){
            ct++;
            idx++;
        }  
        if(lvl!=ct-1){
            idx-=(ct);
            return node; 
        }

        node->left=fun(traversal,ct,idx);


        ct=0;
        while(idx<n && traversal[idx]=='-'){
            ct++;
            idx++;
        }  
        if(lvl!=ct-1){
            idx-=(ct);
            return node; 
        }
        node->right=fun(traversal,ct,idx);



        return node;
        
    }

    TreeNode* recoverFromPreorder(string traversal) {
        n=traversal.size();
        
        int idx=0;
        return fun(traversal,0,idx);




    }
};