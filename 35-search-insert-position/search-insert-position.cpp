class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int result=nums.size();
        while(l<=r){
          int mid=l+(r-l)/2;
          if(nums[mid]>=target){
            result=mid;
            r=mid-1;
          }else{
            l=mid+1;
          }
        }  
        return result; 
      }
};