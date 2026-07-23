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
    int dp[1000][2][2];
    
    int fun(TreeNode* node,int litUp,int H){
        
        if(dp[node->val][litUp][H]!=-1)return dp[node->val][litUp][H];
        int ans=0;
        if(litUp==0){
            int here=1+fun(node,1,1);
            int l=INT_MAX;
            int r=INT_MAX;
            int lr1=INT_MAX;
            int lr2=INT_MAX;
            
            if(node->left!=NULL){
                
                l=1+fun(node->left,1,1);
                if(node->right!=NULL){
                    
                    l+=fun(node->right,0,0);
                    

                }
                
            }
            if(node->right!=NULL){
                
                r=1+fun(node->right,1,1);
                if(node->left!=NULL){
                    
                    r+=fun(node->left,0,0);
                    
                }
                
            }
            //
            if(node->left!=NULL){
                lr1=1+fun(node->left,1,1);
                if(node->right!=NULL){
                    lr1+=1+fun(node->right,1,1);
                }
            }if(node->right!=NULL){
                lr2=1+fun(node->right,1,1);
                if(node->left!=NULL){
                    lr2+=1+fun(node->left,1,1);
                }
            }

            
            ans=min({l,r,lr1,lr2,here});
        }   
        else if(H==0){
            int l=0;
            
            if(node->left!=NULL){
                
                
                l+=fun(node->left,0,0);
                
            }if(node->right!=NULL){
                
                
                l+=fun(node->right,0,0);
                
            }
            
            ans=l;

        }
        else{
            int l=0;
            int l1=INT_MAX;
            int r1=INT_MAX;
            int lr1=0;
        
            if(node->left!=NULL){
                
                
                l+=fun(node->left,1,0);

            }if(node->right!=NULL){
                
                
                l+=fun(node->right,1,0);
            }
//
            if(node->left!=NULL){
                
                l1=1+fun(node->left,1,1);
                if(node->right!=NULL){
                    l1+=fun(node->right,1,0);
                }

            }

            
            
//
            
            if(node->right!=NULL){
                
                
                r1=1+fun(node->right,1,1);
                if(node->left!=NULL){
                    r1+=fun(node->left,1,0);
                }
            }
//          
            if(node->left!=NULL){


                lr1+=1+fun(node->left,1,1);
            }if(node->right!=NULL){


                lr1+=1+fun(node->right,1,1);
            }
            ans=min({l,l1,r1,lr1});

        }
        return dp[node->val][litUp][H]=ans;






        

    
    }
    int minCameraCover(TreeNode* root) {
        memset(dp,-1,sizeof(dp));
        queue<TreeNode*>q;
        q.push(root);
        int it=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            node->val=it;
            it++;
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);

            }
            if(node->right!=NULL){
                q.push(node->right);

            }
            
            

        }
        return fun(root,0,0);
    }
};