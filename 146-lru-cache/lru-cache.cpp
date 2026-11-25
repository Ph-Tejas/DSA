class List{
public:
    int key;
    int val;
    List* nxt;
    List* prv;
    List(int key,int val){
        this->key=key;
        this->val=val;
        nxt=NULL;
        prv=NULL;

    }
};
class LRUCache {

public:
    int mx;
    map<int,List*>mp;
    int first;
    int last;
    
    LRUCache(int capacity) {
        mx=capacity;

        
    }
    void change(int key){
        if(key==first) return; 
        List* forw=mp[key]->nxt;
        List* back=mp[key]->prv;

        mp[key]->nxt=mp[first];
        mp[key]->prv=NULL;
        mp[first]->prv=mp[key];
        first=key;
        if(forw!=NULL)forw->prv=back;
        else {
            if(back!=NULL)last=back->key;
        }
        if(back!=NULL)back->nxt=forw;
        
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end()){
            change(key);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.size()==0){
            mp[key]=new List(key,value);
            first=key;
            last=key;
            return;
        }

        if(mp.find(key)!=mp.end()){
            mp[key]->val=value;
            change(key);
        }
        else{
            mp[key]=new List(key,value);
            mp[key]->nxt=mp[first];
            mp[first]->prv=mp[key];
            first=key;
            if(mp.size()>mx){
                int back=mp[last]->prv->key;
                mp[back]->nxt=NULL;
                mp[last]->prv=NULL;
                mp.erase(last);
                last=back;

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