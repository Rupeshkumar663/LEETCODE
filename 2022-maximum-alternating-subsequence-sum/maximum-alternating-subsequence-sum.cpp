//T.C-O(2^n)
//Recursion
/*
class Solution {
public:
int n;
   long long solve(int idx,vector<int>&nums,bool flag){
    if(idx>=n){
        return 0;
    }
    long long skip=solve(idx+1,nums,flag);
    long long val=nums[idx];
    if(flag!=true){
        val=-val;
    }
    long long take=solve(idx+1,nums,!flag)+val;
    return max(take,skip);
   }
    long long maxAlternatingSum(vector<int>& nums) {
         n=nums.size();
       return  solve(0,nums,true);
    }
};
*/

class Solution {
public:
 long long dp[1000001][2];
  int n;
   long long solve(int idx,vector<int>&nums,bool flag){
    if(idx>=n){
        return 0;
    }
    if(dp[idx][flag]!=-1){
        return dp[idx][flag];
    }
    long long skip=solve(idx+1,nums,flag);
    long long val=nums[idx];
    if(flag!=true){
        val=-val;
    }
    long long take=solve(idx+1,nums,!flag)+val;
    return dp[idx][flag]=max(take,skip);
   }
    long long maxAlternatingSum(vector<int>& nums) {
         n=nums.size();
         memset(dp,-1,sizeof(dp));
       return  solve(0,nums,true);
    }
};