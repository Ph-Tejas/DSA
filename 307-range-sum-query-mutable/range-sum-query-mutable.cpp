class NumArray {
public:
    int n;
    vector<int>segmentTree;
    vector<int>numbers;
    NumArray(vector<int>& nums) {
        n=nums.size();
        numbers=nums;
        segmentTree.resize(4*n);
        build(0,n-1,0);

    }
    int build(int i,int j,int ind){
        if(i==j)return segmentTree[ind]=numbers[j];
        int mid=i+(j-i)/2;
        return segmentTree[ind]=build(i,mid,2*ind+1)+build(mid+1,j,2*ind+2);
    }
    void upd(int i,int j,int &index,int &diff,int ind){
        if(index>j ||index<i)return;

        segmentTree[ind]+=diff;
        if(i==j){
            return;
        }
        int mid=i+(j-i)/2;

        upd(i,mid,index,diff,2*ind+1);
        upd(mid+1,j,index,diff,2*ind+2);
            
    }
    void update(int index, int val) {

        int diff=val-numbers[index];
        // cout<<diff<<" ";
        numbers[index]=val;
        upd(0,n-1,index,diff,0);
    }

    int findSum(int i,int j,int &left,int &right,int ind){
        if(left > j|| right<i)return 0;
        if(left<=i && right>=j )return segmentTree[ind];
        int mid=i+(j-i)/2;

        return findSum(i,mid,left,right,2*ind+1)+findSum(mid+1,j,left,right,2*ind+2);
        
    }
    int sumRange(int left, int right) {
        return findSum(0,n-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */