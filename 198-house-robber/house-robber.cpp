
//T.c-O(2^n)
//Recursion
/*
class Solution {
public:
 int solve(int n,vector<int>&nums){
    if(n<0)
      return 0;
    if(n==0){
         return nums[0];
    }
    int steal=nums[n]+solve(n-2,nums);
    int skip=solve(n-1,nums);
    return max(steal,skip);
}
    int rob(vector<int>& nums) {
       int n=nums.size();
      return solve(n-1,nums);
    }
};
*/
//T.c-O(n)
//s.c-O(n)
/*
class Solution {
public:
int dp[101];
 int solve(int n,vector<int>&nums){
    if(n<0)
      return 0;
      if(dp[n]!=-1){
        return dp[n];
      }
    int steal=nums[n]+solve(n-2,nums);
    int skip=solve(n-1,nums);
    return dp[n]=max(steal,skip);
}
    int rob(vector<int>& nums) {
       int n=nums.size();
       memset(dp,-1,sizeof(dp));
       return solve(n-1,nums);
     
    }
};
*/
class Solution {
public:

 
    int rob(vector<int>& nums) {
       int n=nums.size();
       vector<int>dp(n+1,0);
       dp[0]=0;
       dp[1]=nums[0];
       for(int i=2;i<=n;i++){
        int steal=nums[i-1]+dp[i-2];
        int skip=dp[i-1];
         dp[i]=max(steal,skip);
       }
       return dp[n];
    }
};