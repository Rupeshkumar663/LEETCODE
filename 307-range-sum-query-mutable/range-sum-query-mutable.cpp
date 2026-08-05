class NumArray {
public:
  int n;
   vector<int>segmentTree;

   void buildSegmentTree(int i,int l,int r,vector<int>& nums){
     if(l==r){
        segmentTree[i]=nums[l];
        return ;
     }
     int mid=l+(r-l)/2;
     buildSegmentTree(2*i+1,l,mid,nums);//left
     buildSegmentTree(2*i+2,mid+1,r,nums);//right
    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
   }

   void updateSegmentTree(int &index,int &val,int i,int l,int r){
      if(l==r){
        segmentTree[i]=val;
        return ;
     }
     int mid=l+(r-l)/2;
     if(index<=mid)
     updateSegmentTree(index,val,2*i+1,l,mid);//left
     else
      updateSegmentTree(index,val,2*i+2,mid+1,r);//right
     segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
   }

  int QuerySegmentTree(int start,int end,int i,int l,int r){
    if(r<start || end<l){//out of bound
        return 0;
    }
    if(start<=l && r<=end){//entire 'l' and 'r' in my query
       return segmentTree[i];
    }
    int mid=l+(r-l)/2;
    return QuerySegmentTree(start,end,2*i+1,l,mid)+QuerySegmentTree(start,end,2*i+2,mid+1,r);
  }
    NumArray(vector<int>& nums) {
        n=nums.size();
        segmentTree.resize(4*n);
       buildSegmentTree(0,0,n-1,nums);//build Segment Tree
    }
    
    void update(int index, int val) {
        updateSegmentTree(index,val,0,0,n-1);//update in segment Tree
    }
    
    int sumRange(int left, int right) {
       return QuerySegmentTree(left,right,0,0,n-1);//Range Query
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */