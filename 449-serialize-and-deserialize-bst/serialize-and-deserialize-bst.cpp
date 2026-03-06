/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string fin="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int value;
            TreeNode* l;
            TreeNode* r;
            if(q.front()==NULL){
                fin+="null#";
                q.pop();
                continue;
            }
            value=q.front()->val;
            l=q.front()->left;
            r=q.front()->right;
            fin+=to_string(value);
            fin+="#";
            q.pop();
            q.push(l);
            q.push(r);



        }
        return fin;

    }

    // Decodes your encoded data to tree.
    void rec(int &it,vector<int>&fin,vector<TreeNode*>toPursue){
        if(toPursue.size()==0)return;
        vector<TreeNode*>willPursue;
        for(int i=0;i<toPursue.size();i++){
            if(toPursue[i]==NULL)continue;
            if(fin[it]==20000){
                toPursue[i]->left=NULL;
            }
            else toPursue[i]->left=new TreeNode(fin[it]);
            willPursue.push_back(toPursue[i]->left);
            it++;
            if(fin[it]==20000){
                toPursue[i]->right=NULL;

            }
            else{
                toPursue[i]->right=new TreeNode(fin[it]);
            }
            willPursue.push_back(toPursue[i]->right);
            it++;
        }
        rec(it,fin,willPursue);

    }
    TreeNode* deserialize(string data) {
        
        vector<int>fin;
        string temp;
        for(int i=0;i<data.size();i++){
            if(data[i]=='#'){
                if(temp[0]=='n'){
                    fin.push_back(20000);
                }
                else fin.push_back(stoi(temp));
                temp.clear();
                continue;
            }
            temp.push_back(data[i]);

        }
        if(fin.size()==1){
            return NULL;
        }
        int it=1;
        TreeNode* head=new TreeNode(fin[0]);
        
        rec(it,fin,{head});
        return head;
        



    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));