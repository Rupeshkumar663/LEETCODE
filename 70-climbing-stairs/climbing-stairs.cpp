//T.C-O(2^n)
//Recursion Approach--------
/*
class Solution {
public:
int solve(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    return solve(n-1)+solve(n-2);
  }
    int climbStairs(int n) {
        int one_step=solve(n-1);
        int two_step=solve(n-2);
        return one_step+two_step;
    }
};
*/
//T.c-O(n)
//s.c-O(n)
//Recursion+memoization--------------
/*
class Solution {
public: 
int solve(int n,vector<int>&dp){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1)
      return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
  }
    int climbStairs(int n) {
      vector<int>dp(n+1,-1);
     return solve(n,dp);
      
    }
};
*/
//T.c-O(n)
//s.c-O(n)
//Bottom up approach------------
/*
class Solution {
public: 
    int climbStairs(int n) {
    vector<int>dp(n+1,-1);
     dp[0]=1;
     dp[1]=1;
     for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
     }
      return dp[n];
    }
};

class Solution {
public: 
    int climbStairs(int n) {
     if(n==1 || n==2){
        return n;
     }
     int a=1;
     int b=2;
     int c=3;
     for(int i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
     }
     return c;
    }
};
*/
class Solution {
public: 
int solve(int n,vector<int>&dp){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1)
      return dp[n];
    return dp[n]=solve(n-1,dp)+solve(n-2,dp);
  }
    int climbStairs(int n) {
      vector<int>dp(n+1,-1);
     return solve(n,dp);
      
    }
};