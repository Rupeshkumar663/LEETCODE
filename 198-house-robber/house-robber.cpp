
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
//recursion+memoization
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
//T.c-O(n)
//s.c-O(n)
//bottom up approach--------------------------
/*
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

//T.c-O(n)
//s.c-O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
       int n=nums.size();
       int a=0;
       int b=nums[0];
       int c=0;
       for(int i=2;i<=n;i++){
        c=nums[i-1]+a;
         c=max(c,b);
         a=b;
         b=c;
       }
       return b;
    }
};

//Time Complexity: O(2^n)
//Space Complexity: O(1)
//Recursion Approach-------------
class Solution {
public:
   int n;
   int solve(int i,int sum,vector<int>&nums){
     if(i>=n){
        return sum;
     }
     int take=solve(i+2,sum+nums[i],nums);
     int skip=solve(i+1,sum,nums);
     return max(take,skip);
   }
    int rob(vector<int>& nums) {
      n=nums.size();
     return solve(0,0,nums);
    }
};
*/
//Time Complexity: O(2^n)
//Space Complexity: O(1)
//Recursion Approach-------------
class Solution {
public:
   int n;
   int dp[101];
   int solve(int i,vector<int>&nums){
     if(i>=n){
        return 0;
     }
     if(dp[i]!=-1)
       return dp[i];
     int take=nums[i]+solve(i+2,nums);
     int skip=solve(i+1,nums);
     return dp[i]=max(take,skip);
   }
    int rob(vector<int>& nums) {
      n=nums.size();
      memset(dp,-1,sizeof(dp));
     return solve(0,nums);
    }
};