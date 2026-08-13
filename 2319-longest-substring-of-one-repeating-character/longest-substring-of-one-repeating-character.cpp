class Node{
public:

    int maxLength;
    int pf;
    int sf;
    char pc;
    char sc;
    Node(int maxLength,int pf,int sf,char pc,char sc){
        this->maxLength=maxLength;
        this->pf=pf;
        this->sf=sf;
        this->pc=pc;
        this->sc=sc;
        
    } 
    

};
class Solution {
public:
    
    Node* segTree[400000];

    bool intersectionSame(Node* &l,Node* &r){
        return (l->sc)==(r->pc);

    }
    Node* findFin(Node* l,Node* r,int i,int j,int mid){
        int mx=max(l->maxLength,r->maxLength);
        int sz,pz;

        if(intersectionSame(l,r)){
            
            mx=max(mx,(l->sf)+(r->pf));
            
        }
        if(j-(mid+1)+1==r->sf){
            if(intersectionSame(l,r)){
                sz=j-(mid+1)+1+l->sf;
            }
            else{
                sz=r->sf;
            }
        }
        else{
            sz=r->sf;
        }
        if(mid-i+1==l->pf){
            if(intersectionSame(l,r)){
                pz=mid-i+1+r->pf;
            }
            else{
                pz=l->pf;
            }
        }
        else pz=l->pf;
        char chp=l->pc;
        char chs=r->sc;
        Node* ans=new Node(mx,pz,sz,chp,chs);
        return ans;
    }

    Node* build(int i,int j,string &s,int ind){
        if(i==j){
            segTree[ind]=new Node(1,1,1,s[i],s[j]);
            return segTree[ind];
        }
        int mid=i+(j-i)/2;
        Node* l=build(i,mid,s,2*ind+1);
        Node* r=build(mid+1,j,s,2*ind+2);


        return segTree[ind]=findFin(l,r,i,j,mid);


    }


    Node* update(int loc,int ch,int i,int j,int ind,string &s){
        
        if(i>loc||j<loc)return segTree[ind];
        if(i==j){
            segTree[ind]->sc=ch;
            segTree[ind]->pc=ch;
            return segTree[ind];
        }
        int mid=i+(j-i)/2;
        Node* l=update(loc,ch,i,mid,2*ind+1,s);
        Node* r=update(loc,ch,mid+1,j,2*ind+2,s);

   

        return segTree[ind]=findFin(l,r,i,j,mid);


        

    }



    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.size();
        int m=queryCharacters.size();
        memset(segTree,NULL,sizeof(segTree));

        build(0,n-1,s,0);
        
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            int ch=queryCharacters[i];
            int loc=queryIndices[i];



            Node* res=update(loc,ch,0,n-1,0,s);
            
            ans[i]=res->maxLength;

        }
        return ans;












    }
};