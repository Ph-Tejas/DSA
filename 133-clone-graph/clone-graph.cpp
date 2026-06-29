/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int,Node*>mp;
    Node* build(Node* node){
        if(node==NULL){
            return node;
        }
        Node* curr=new Node(node->val);
        if(mp.find(node->val)!=mp.end()){
            return mp[node->val];
        }
        mp[node->val]=curr;

        for(int i=0;i<node->neighbors.size();i++){
            curr->neighbors.push_back(build(node->neighbors[i]));
        }
        return curr;
    }
    Node* cloneGraph(Node* node) {
     
        return build(node);
        
    }
};