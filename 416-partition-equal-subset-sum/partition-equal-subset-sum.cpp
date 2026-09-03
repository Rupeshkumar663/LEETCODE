/*

//Time Complexity: O(2^n)
//Space Complexity: O(1)
//Recursion Approach--------------------
class Solution {
public:
   bool Solve(vector<int>&nums,int i,int sum){
    //Base Case of Recursion Tree
    if(sum==0){
        return true;
    }
    if(i==nums.size()){
        return false;
    }
   //Recursive Case
    bool take;
    if(sum>=nums[i]){
        take=Solve(nums,i+1,sum-nums[i]);
    }
    bool skip=Solve(nums,i+1,sum);
    //Return Case
    return take || skip;
   }
    bool canPartition(vector<int>& nums) {
       int sum=accumulate(nums.begin(),nums.end(),0);
       if(sum%2!=0){
        return false;
       }
       return Solve(nums,0,sum/2);
    }
};*/

/*

//Time Complexity: O(2^n)
//Space Complexity: O(1)
//Recursion +Memoization Approach--------------------
//Move Left->Right
class Solution {
public:
int dp[201][10001];
   bool Solve(vector<int>&nums,int i,int sum){
    //Base Case of Recursion Tree
    if(sum==0){
        return true;
    }
    if(i==nums.size()){
        return false;
    }

    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
   //Recursive Case
    bool take;
    if(sum>=nums[i]){
        take=Solve(nums,i+1,sum-nums[i]);
    }
    bool skip=Solve(nums,i+1,sum);
    //Return Case
    return dp[i][sum]=take || skip;
   }
    bool canPartition(vector<int>& nums) {
       int sum=accumulate(nums.begin(),nums.end(),0);
       if(sum%2!=0){
        return false;
       }
       memset(dp,-1,sizeof(dp));
       return Solve(nums,0,sum/2);
    }
};*/
/*//Time Complexity: O(2^n)
//Space Complexity: O(1)
//Recursion +Memoization Approach--------------------
//Move Right->Left
class Solution {
public:
int dp[201][100001];
   bool Solve(vector<int>&nums,int i,int sum){
    //Base Case of Recursion Tree
    if(sum==0){
        return true;
    }
    if(i==0){
        return false;
    }

    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
   //Recursive Case
    bool take;
    if(sum>=nums[i-1]){
        take=Solve(nums,i-1,sum-nums[i-1]);
    }
    bool skip=Solve(nums,i-1,sum);
    //Return Case
    return dp[i][sum]=take || skip;
   }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
       int sum=accumulate(nums.begin(),nums.end(),0);
       if(sum%2!=0){
        return false;
       }
       memset(dp,-1,sizeof(dp));
       return Solve(nums,n-1,sum/2);
    }
};
*/

//Time Complexity: O(2^n)
//Space Complexity: O(1)
//Tabulation/Bottom-Up Approach--------------------
/*
class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
       int sum=accumulate(nums.begin(),nums.end(),0);
       if(sum%2!=0){
        return false;
       }
       vector<vector<bool>>dp(n+1,vector<bool>((sum/2)+1,false));
       for(int i=0;i<n;i++){
        dp[i][0]=true;
       }
       for(int i=1;i<n+1;i++){
        for(int j=1;j<dp[0].size()+1;j++){
            bool take=false;
           if(j>=nums[i-1]){
              take=dp[i-1][j-nums[i-1]];
            }
          bool skip=dp[i-1][j];
    
         dp[i][j]=take || skip;
        }
       }
       return dp[n][sum/2];
    }
};
*/

class Solution {
public:
  int n;
  int dp[201][100000];
  bool Solve(int i,int target,vector<int>&nums){
    if(target==0){
        return true;
    }
    if(i==n){
        return false;
    }
    
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
   bool take=0;
    if(target>=nums[i]){
      take=Solve(i+1,target-nums[i],nums);
    }
    bool skip=Solve(i+1,target,nums);
     return dp[i][target]=skip || take;
  }
    bool canPartition(vector<int>& nums) {
         n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1){
            return false;
        }
        memset(dp,-1,sizeof(dp));
      return   Solve(0,sum/2,nums);
    }
};