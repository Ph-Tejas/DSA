/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* build(int i1,int j1,int i2,int j2,vector<vector<int>>& grid){
        bool flag=true;
        // cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<endl;
        int value=grid[i2][i1];
        for(int i=i2;i<=j2;i++){
            for(int j=i1;j<=j1;j++){
                if(value!=grid[i][j]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            return new Node(value,1);
        }
        Node* node=new Node(0,0);
        
        int mid1=i1+(j1-i1)/2;

        int mid2=i2+(j2-i2)/2;

        node->topLeft=build(i1,mid1,i2,mid2,grid);

        node->topRight=build(mid1+1,j1,i2,mid2,grid);

        node->bottomLeft=build(i1,mid1,mid2+1,j2,grid);
        
        node->bottomRight=build(mid1+1,j1,mid2+1,j2,grid);
        return node;

    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return build(0,n-1,0,n-1,grid);
    }
};