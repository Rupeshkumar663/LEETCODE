/*//Time COmplexity: O(2^n)
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
};*/

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
};