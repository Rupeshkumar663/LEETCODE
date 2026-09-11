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
/*//Time Complexity: O(n*n)
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
};*/

/*//Time Complexity: O(n*n)
//Space COmplexity: O(n*n)
//Recursion +Memoization Approach------------
class Solution {
public:
 int n;
    int Solve(int i,int amount,vector<int>& coins){
        if(amount==0){
            return 1;
        }
        f(i==n){
            return 0;
        }
        int take=0;
        if(amount[i]>=coins[i]){
            take=Solve(i+1,amount-coins[i],coins);
        }
        int take=Slve(i+1,amount,coins);
        return skip+take;
    }
    int coinChange(vector<int>& coins, int amount) {
      n=coins.size();
      return Solve(0,amount,count,coins);
    }
};*/


//Time Complexity: O(n*n)
//Space COmplexity: O(n*n)
//Recursion +Memoization Approach------------
class Solution {
public:
 int n;
 int dp[13][10001];
  int Solve(int i,int amount,vector<int>& coins){
    if(amount==0){
        return 0;
    }
    if(i==n){
        return INT_MAX;
    }
   if(dp[i][amount]!=-1){
    return dp[i][amount];
   }
   int take=INT_MAX;
   if(amount>=coins[i]){
     take=Solve(i,amount-coins[i],coins);
     if(take!=INT_MAX){
        take++;
     }
   }
   int skip=Solve(i+1,amount,coins);
    return dp[i][amount]=min(skip,take);
  }
    int coinChange(vector<int>& coins, int amount) {
      n=coins.size();
      memset(dp,-1,sizeof(dp));
      return Solve(0,amount,coins)==INT_MAX?-1:Solve(0,amount,coins);
    }
};