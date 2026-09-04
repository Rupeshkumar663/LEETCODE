/*
//Time COmplexity: O(2^n)
//Space Complexity: O(1)
//By Recursion Approach------------
class Solution {
public:
 int solve(int i,int amount, vector<int>& coins){
    if(amount==0)
       return 1;
    if(i==coins.size())
      return 0;
    int take=0;
    if(amount>=coins[i]){
        take=solve(i,amount-coins[i],coins);
    }
    int skip=solve(i+1,amount,coins);
    return skip+take;
 } 
    int change(int amount, vector<int>& coins) {
     return solve(0,amount,coins); 
    }
};
*/

/*
//Time COmplexity: O(n*n)
//Space Complexity: O(n*n)
//By Recursion +Memoization Approach------------
class Solution {
public:
int dp[301][5001];
 int solve(int i,int amount, vector<int>& coins){
    if(amount==0)
       return 1;
    if(i==coins.size())
      return 0;

    if(dp[i][amount]!=-1){
        return dp[i][amount];
    }
    int take=0;
    if(amount>=coins[i]){
        take=solve(i,amount-coins[i],coins);
    }
    int skip=solve(i+1,amount,coins);
    return dp[i][amount]=skip+take;
 } 
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
     return solve(0,amount,coins); 
    }
};*/

/*//Time COmplexity: O(n*n)
//Space Complexity: O(n*n)
//By Recursion +Memoization Approach------------
class Solution {
public:
int dp[301][5001];
 int solve(int i,int amount, vector<int>& coins){
    if(amount==0)
       return 1;
    if(i<0)
      return 0;

    if(dp[i][amount]!=-1){
        return dp[i][amount];
    }
    int take=0;
    if(amount>=coins[i]){
        take=solve(i,amount-coins[i],coins);
        
    }
    /*int take=0;
    if(j>=coins[i]){
        take=dp[i][j-coins[i]];
        
    }
    int skip=solve(i-1,amount,coins);
    return dp[i][amount]=skip+take;
    /* int skip=dp[i-1],[j];
    dp[i][j]=skip+take;
 } 
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
     return solve(n-1,amount,coins); 
    }
};*/


//Time COmplexity: O(n*n)
//Space Complexity: O(n*n)
//By Recursion +Memoization Approach------------
class Solution {
public:
int dp[301][10001];
    int solve(int i,int amount, vector<int>& coins){
        if(amount==0){
            return 1;
        }
        if(i==coins.size()){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int take=0;
        if(amount>=coins[i]){
            take=solve(i,amount-coins[i],coins);
        }
        int skip=solve(i+1,amount,coins);
        return dp[i][amount]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(0,amount,coins);
    }
};