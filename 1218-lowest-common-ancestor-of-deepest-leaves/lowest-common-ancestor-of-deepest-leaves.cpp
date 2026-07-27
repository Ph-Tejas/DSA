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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int howDeep=0;
        vector<TreeNode*>parents(1001,NULL);
        parents[root->val]=new TreeNode(-1);

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int lvl=q.front().second;
            howDeep=lvl;
            q.pop();
            if(node->left!=NULL){
                parents[node->left->val]=node;
                q.push({node->left,lvl+1});
            }
            if(node->right!=NULL){
                parents[node->right->val]=node;
                q.push({node->right,lvl+1});
            }

        }
        queue<TreeNode*>letsCheck;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int lvl=q.front().second;
            if(lvl==howDeep){
                letsCheck.push(node);
            }
            q.pop();
            if(node->left!=NULL){
                q.push({node->left,lvl+1});
            }
            if(node->right!=NULL){
                q.push({node->right,lvl+1});
            }
        }
        int sz=letsCheck.size();
        vector<TreeNode*>v;
        int ct=0;
        if(sz==1)return letsCheck.front();
        while(!letsCheck.empty()){
            TreeNode* node=letsCheck.front();
            letsCheck.pop();

            ct++;
            v.push_back(node);
            if((ct)%sz==0){
                bool ans=true;
                for(int i=1;i<sz;i++){
                    if(v[i]->val!=v[i-1]->val)ans=false;
                }
                if(ans)return v.back();
                v.clear();
            }
            letsCheck.push(parents[node->val]);
        }
        return NULL;
    }
};