//T.C-O(2^n)
//Recursion Approach
/*
class Solution {
public:
    int n;
    int solve(int idx, int prev, vector<int>& nums){
        if (idx>=nums.size()){
            return 0;
        }
        int skip=solve(idx+1,prev,nums);
        int take=0;
        if(prev==-1 || nums[idx]>nums[prev]){
            take=1+solve(idx+1,idx,nums);
        }
        return max(take,skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        return solve(0,-1,nums);
    }
};
*/

//T.C-O(n)
//S.C-O(n)
//Recursion+memoization
/*
class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(int idx,int prev,vector<int>& nums){
        if (idx==nums.size()){
            return 0;
        }
         if(dp[idx][prev+1]!=-1 ){
            return dp[idx][prev+1];
        }
        int skip=solve(idx+1,prev,nums);
        int take=0;
        if(prev==-1 || nums[idx]>nums[prev]){
            take=1+solve(idx+1,idx,nums);
        }
        return dp[idx][prev+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
    }
};


//T.C-O(n^2)
//S.C-O(n)
//Bottom-up Approach

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
        vector<int>dp(n,1);
        int result=1;
         for(int i=1;i<n;i++){
           for(int j=0;j<i;j++){
             if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
             }
             result=max(dp[i],result);
           }
         }
         return result;
    }
};
*/


class Solution {
public:
int n;
int dp[2501][2501];
   int Solve(int i,int prev,vector<int>&nums){
    if(i==n){
        return 0;
    }
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }
    int take=0;
    if(prev==-1 || nums[i]>nums[prev]){
        take=1+Solve(i+1,i,nums);
    }
    int skip=Solve(i+1,prev,nums);
    return dp[i][prev+1]=max(take,skip);
   }
    int lengthOfLIS(vector<int>& nums) {
       n=nums.size();
       memset(dp,-1,sizeof(dp));
       return Solve(0,-1,nums);
    }
};

