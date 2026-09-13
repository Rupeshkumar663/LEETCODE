/*//Time COmplexity: O(2^n)
//Space COmplexity: O(1)
//Recursion Appproach-------------
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
};*/

/*//Time COmplexity: O(2^n)
//Space COmplexity: O(1)
//Recursion + Memoization Appproach-------------
class Solution {
public:
  int dp[21][2001];
  int solve(int i,int sum,vector<int>& nums, int target){
    if(i==nums.size()){
        if(sum==target)
           return 1;
        return 0;
    }
    if(dp[i][1000+sum]!=-1){
        return dp[i][1000+sum];
    }
    int SUM=solve(i+1,sum+nums[i],nums,target);
    int MINUS=solve(i+1,sum-nums[i],nums,target);
    return dp[i][1000+sum]=SUM+MINUS;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
      memset(dp,-1,sizeof(dp));
       return solve(0,0,nums,target);
    }
};*/


/*//Time COmplexity: O(2^n)
//Space COmplexity: O(1)
//Recursion + Memoization Appproach-------------
class Solution {
public:
   int n;
   map<pair<int,int>,int>dp;
   int Solve(int i,int target,vector<int>nums){
    if(i==n){
        if(target==0){
            return 1;
        }
       return 0;
    }
    pair<int,int>temp={i,target};
    if(dp.find(temp)!=dp.end()){
        return dp[temp];
    }
     int add=Solve(i+1,target+nums[i],nums);
     int minus=Solve(i+1,target-nums[i],nums);
     return dp[temp]=add+minus;
   }
    int findTargetSumWays(vector<int>& nums,int target) {
     n=nums.size();
     return Solve(0,target,nums);
    }
};*/

//Time COmplexity: O(2^n)
//Space COmplexity: O(1)
//Recursion + Memoization Appproach-------------
class Solution {
public:
   int n;
   map<pair<int,int>,int>dp;
   int Solve(int i,int target,vector<int>nums){
    if(i<0){
        if(target==0){
            return 1;
        }
       return 0;
    }
    pair<int,int>temp={i,target};
    if(dp.find(temp)!=dp.end()){
        return dp[temp];
    }
     int add=Solve(i-1,target+nums[i],nums);
     int minus=Solve(i-1,target-nums[i],nums);
     return dp[temp]=add+minus;
   }
    int findTargetSumWays(vector<int>& nums,int target) {
     n=nums.size();
     return Solve(n-1,target,nums);
    }
};