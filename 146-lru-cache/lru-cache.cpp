class List{
public:
    int val;
    int keyy;
    List* left;
    List* right;
    List(int k,int value){
        keyy=k;
        val=value;
        left=NULL;
        right=NULL;
    }
    List(int k,int value,List* L){
        keyy=k;
        val=value;
        left=L;
        right=NULL;
    }
    
    
};
class LRUCache {
public:
    List* mostRecent;
    List* leastRecent;
    vector<List*>posOfList;
    int sz;
    int maxSz;
    LRUCache(int capacity) {
        mostRecent=NULL;
        posOfList.resize(1e4+1,NULL);
        sz=0;
        maxSz=capacity;
    }
    
    int get(int key) {
        if(posOfList[key]!=NULL){
            if(posOfList[key]->right==NULL){
                return posOfList[key]->val;
            }
            else if(posOfList[key]->left==NULL){
                int value=posOfList[key]->val;
                List* lstR=posOfList[key]->right;
                lstR->left=NULL;
                leastRecent=lstR;
                mostRecent->right=new List(key,value,mostRecent);
                mostRecent=mostRecent->right;
                posOfList[key]=mostRecent;

            }
            else if(posOfList[key]->left!=NULL&&posOfList[key]->right!=NULL){
                int value=posOfList[key]->val;
                List* lstR=posOfList[key]->right;
                List* lstL=posOfList[key]->left;
                lstR->left=lstL;
                lstL->right=lstR;
                mostRecent->right=new List(key,value,mostRecent);
                mostRecent=mostRecent->right;
                posOfList[key]=mostRecent;
            }

            return posOfList[key]->val;
        }
        else{
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if(sz==0){
            List* lst=new List(key,value);
            posOfList[key]=lst;
            mostRecent=lst;
            leastRecent=lst;
            sz++;

        }
        else if(sz==maxSz){
            if(sz==1){
                int k=leastRecent->keyy;
                List* lst=new List(key,value);
                posOfList[key]=lst;
                mostRecent=lst;
                leastRecent=lst;
                posOfList[k]=NULL;

                return;
            }
            if(posOfList[key]==NULL){
                int k=leastRecent->keyy;
                mostRecent->right=new List(key,value,mostRecent);
                mostRecent=mostRecent->right;
                posOfList[key]=mostRecent;
                List* lstR=leastRecent->right;
                lstR->left=NULL;
                leastRecent=lstR;
                posOfList[k]=NULL;

                
            }
            else{
                if(posOfList[key]->right==NULL){
                    posOfList[key]->val=value;
                    return;
                }
                if(posOfList[key]->left==NULL){
                    List* lstR=posOfList[key]->right;
                    lstR->left=NULL;
                    leastRecent=lstR;
                    mostRecent->right=new List(key,value,mostRecent);
                    mostRecent=mostRecent->right;
                    posOfList[key]=mostRecent;
                }
                else{
                    List* lstR=posOfList[key]->right;
                    List* lstL=posOfList[key]->left;
                    lstR->left=lstL;
                    lstL->right=lstR;
                    mostRecent->right=new List(key,value,mostRecent);
                    mostRecent=mostRecent->right;
                    posOfList[key]=mostRecent;
                }

            }

            
        }
        else{
            if(posOfList[key]==NULL){
                mostRecent->right=new List(key,value,mostRecent);
                mostRecent=mostRecent->right;
                posOfList[key]=mostRecent;
                sz++;
            }
            else{
                if(posOfList[key]->right==NULL){
                    posOfList[key]->val=value;
                    return;
                }

                if(posOfList[key]->left==NULL){
                    List* lstR=posOfList[key]->right;
                    lstR->left=NULL;
                    leastRecent=lstR;
                    mostRecent->right=new List(key,value,mostRecent);
                    mostRecent=mostRecent->right;
                    posOfList[key]=mostRecent;
                }
                else{
                    List* lstR=posOfList[key]->right;
                    List* lstL=posOfList[key]->left;
                    lstR->left=lstL;
                    lstL->right=lstR;
                    mostRecent->right=new List(key,value,mostRecent);
                    mostRecent=mostRecent->right;
                    posOfList[key]=mostRecent;
                }

            }
        }


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */