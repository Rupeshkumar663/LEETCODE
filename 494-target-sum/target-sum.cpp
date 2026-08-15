class Solution {
public:
  int solve(int i,int sum,vector<int>& nums, int target){
    if(i==nums.size()){
        if(sum==target)
           return 1;
        return 0;
    }
    int SUM=solve(i+1,sum+nums[i],nums,target);
    int MINUS=solve(i+1,sum-nums[i],nums,target);
    return SUM+MINUS;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
       return solve(0,0,nums,target);
    }
};