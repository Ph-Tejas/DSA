class Node{
public:
    int val;
    pair<int,int>front_back;
    pair<int,int>range;
    Node* left;
    Node* right;
    Node(pair<int,int>pr){
        front_back={0,0};
        range=pr;
        left=nullptr;
        right=nullptr;
    }


};


class Solution {
public:
    vector<bool>vis;
    void build(Node* node){
        int i=node->range.first;
        int j=node->range.second;
        
        node->front_back={j-i,j-i};
        node->val=j-i;
        
        if(i==j){
            return;
        }
        int mid=i+((j-i)/2);
        pair<int,int>pr={i,mid};
    
        Node* l=new Node(pr);
        pr={mid+1,j};
        Node* r=new Node(pr);
        node->left=l;
        node->right=r;
        build(l);
        build(r);
    
    }
    void blocking(Node* node,int x){
        if(node==NULL)return;
        int i=node->range.first;
        int j=node->range.second;
        if(i==j){
            return;
        }
        int mid=i+((j-i)/2);
        if(x<=mid){
            blocking(node->left,x);
        }
        else blocking(node->right,x);
        node->val=max({
            node->left->val,
            node->right->val,
            (node->left->front_back.second)+(node->right->front_back.first)+1
        });
        int lenL = node->left->range.second - node->left->range.first ;
        int lenR = node->right->range.second - node->right->range.first ;
        if((node->left->front_back.first)==lenL){
            node->front_back.first=min({node->front_back.first,(node->left->front_back.first)+(node->right->front_back.first)+1,x-i});
        }
        else{
            node->front_back.first=min({node->front_back.first,(node->left->front_back.first),x-i});
        }
        if((node->right->front_back.second)==lenR){
            node->front_back.second=min({node->front_back.second,(node->left->front_back.second)+(node->right->front_back.second)+1,j-x});
        }
        else{
            node->front_back.second=min({node->front_back.second,(node->right->front_back.second),j-x});
        }

    }
    int check(Node* node,int x){
        int maxi=0;
        int curr=0;
        int residue=0;
        while(true){
            int i=node->range.first;
            int j=node->range.second;
            if(i==j){
                maxi=max(maxi,residue+1);
                break;

            }
            
            int mid=i+(j-i)/2;
            if(x<=mid){
                node=node->left;
                
            }
            else{
                maxi=max(maxi,node->left->val);
                curr=node->left->front_back.first;
                int comp;
                if(i!=0)comp=curr+residue+1;
                else comp=curr+residue;
                if(comp>maxi)maxi=comp;
                int lenL = node->left->range.second - node->left->range.first;
                if(curr==lenL){
                    if(vis[node->left->range.second]==true){
                        residue=0;
                    }
                    else if(node->left->range.first==0){
                        residue=curr;
                    }
                    else {
                        if(vis[node->left->range.first]==true){
                            residue=curr;
                        }

                        else residue+=curr+1;
                    }
                }
                else{
                    residue=node->left->front_back.second;
                }
                // cout<<curr<<" "<<residue<<endl;
                if(residue>maxi)maxi=residue;
                node=node->right;
                

            }
        }
        // cout<<endl;
        return maxi;
        
    }
    // void letscheck(Node* head){
    //     if(head==NULL)return ;
    //     cout<<head->range.first<<" "<<head->range.second<<"                 "<<head->val<<" "<<head->front_back.first<<" "<<head->front_back.second<<" "<<endl;
    //     letscheck(head->left);
    //     letscheck(head->right);
    // }
    vector<bool> getResults(vector<vector<int>>& queries) {

        int q=queries.size();
        
        int maxi=INT_MIN;
        for(int i=0;i<q;i++){
            maxi=max(maxi,queries[i][1]);
            
        }
        vis.resize(maxi+1,false);
        pair<int,int>pr={0,maxi};

        Node* head=new Node(pr);
        build(head);
        vector<bool>ans;
        for(int i=0;i<q;i++){
            int queryNo=queries[i][0];
            int x=queries[i][1];
            if(queryNo==1){
                blocking(head,x);
                vis[x]=true;
            }
            else{
                int req=queries[i][2];
                if(req<=check(head,x)){
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }
            }
                
        }
        // letscheck(head);
        return ans;


        
    }
};