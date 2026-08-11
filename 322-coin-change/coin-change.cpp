//Time Complexity: O(2^n)
//Space COmplexity: O(1)
//Recursion Approach------------
/*class Solution {
public:
int n;
   int solve(int i,vector<int>& coins, int amount,int count){
     if(amount==0){
        return count;
     }
     if(i==coins.size()){
        return INT_MAX;
     }
     int take=INT_MAX;
     if(amount>=coins[i]){
        take=solve(i,coins,amount-coins[i],count+1);
     }
     int skip=solve(i+1,coins,amount,count);
     return min(take,skip);
   }
    int coinChange(vector<int>& coins, int amount) {
       n=coins.size();
       int result=solve(0,coins,amount,0);
        if(result==INT_MAX)
          return -1;
        return result;
    }
};*/
//Time Complexity: O(n*n)
//Space COmplexity: O(n*n)
//Recursion +Memoization Approach------------
class Solution {
public:
int n;
int dp[13][10001];
   int solve(int i,vector<int>& coins, int amount){
     if(amount==0){
        return 0;
     }
     if(i==coins.size()){
        return INT_MAX;
     }
     if(dp[i][amount]!=-1){
        return dp[i][amount];
     }
     int take=INT_MAX;
     if(amount>=coins[i]){
        take=solve(i,coins,amount-coins[i]);
        if(take!=INT_MAX)
          take=take+1;
     }
     int skip=solve(i+1,coins,amount);
     return dp[i][amount]=min(take,skip);
   }
    int coinChange(vector<int>& coins, int amount) {
       n=coins.size();
       memset(dp,-1,sizeof(dp));
       int result=solve(0,coins,amount);
        if(result==INT_MAX)
          return -1;
        return result;
    }
};