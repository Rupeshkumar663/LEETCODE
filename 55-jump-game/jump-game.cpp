/*
 class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n=nums.size();
         int maxi=0;
         for(int i=0;i<n;i++){
            if(i>maxi){
                return false;
            }
            maxi=max(maxi,i+nums[i]);
         }
         return true;
    }
};
*/
/*class Solution {
public:
  int n;
    bool solve(vector<int>& nums,int idx){
        if(idx==n-1){
            return true;
        }
        for(int i=1;i<=nums[idx];i++){
            if(solve(nums,idx+1)==true){
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        return solve(nums,0);
    }
};*/


class Solution {
public:
    bool solve(int maxi,vector<int>& nums){
      for(int i=0;i<nums.size();i++){
        if(maxi==i){
            maxi+=nums[i];
        }
        if(maxi<i){
            return false;
        }else{
            maxi=max(maxi,i+nums[i]);
            if(maxi>=nums.size()-1){
                return true;
            }
        }
      }
      return true;
    }
    bool canJump(vector<int>& nums) {
      if(nums.size()==0){
        return true;
      }
      return solve(0,nums);
    }
};