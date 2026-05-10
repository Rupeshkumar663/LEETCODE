//t.c-O(n)
//s.c-O(n)
//Recusrion+memoization
class Solution {
public:
  int solve(vector<int>& nums,vector<int>&dp,int i,int n){
    if(i>n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int steal=nums[i]+solve(nums,dp,i+2,n);
    int skip=solve(nums,dp,i+1,n);
    return dp[i]=max(steal,skip);
  }
    int rob(vector<int>& nums) {
       int n=nums.size();
       if(n==1){
        return nums[0];
       } 
       if(n==2){
        return max(nums[0],nums[1]);
       }
       vector<int>dp(n+1,-1);
        int taking_0th=solve(nums,dp,0,n-2);
        fill(dp.begin(),dp.end(),-1);
        int not_taking_0th=solve(nums,dp,1,n-1);
        return max(taking_0th,not_taking_0th);
    }
};