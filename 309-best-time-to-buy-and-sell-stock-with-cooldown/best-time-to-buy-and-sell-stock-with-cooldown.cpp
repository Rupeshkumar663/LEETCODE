/*//Time COmplexity: O(2^n)
//SPace COmplexity: O(1)
//Recursion Approach------------
class Solution {
public:
 int n;
 int solve(int i,bool buy,vector<int>&prices){
    if(i>=n){
        return 0;
    }
    int profit=0;
    int take=0;
    if(buy==true){//buy-----------------
        take=solve(i+1,false,prices)-prices[i];
        int not_take=solve(i+1,true,prices);
        profit=max({profit,take,not_take});
    }else{
        take=solve(i+2,true,prices)+prices[i];
        int not_take=solve(i+1,false,prices);
        profit=max({profit,take,not_take});
    }
    return profit;
 }
    int maxProfit(vector<int>& prices) {
     n=prices.size();
     return solve(0,true,prices);
    }
};*/

/*//Time COmplexity: O(n)
//SPace COmplexity: O(n)
//Recursion + Memoization Approach------------
class Solution {
public:
 int n;
 int dp[5001][2];
 int solve(int i,bool buy,vector<int>&prices){
    if(i>=n){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    int profit=0;
    int take=0;
    if(buy==true){//buy-----------------
        take=solve(i+1,false,prices)-prices[i];
        int not_take=solve(i+1,true,prices);
        profit=max({profit,take,not_take});
    }else{
        take=solve(i+2,true,prices)+prices[i];
        int not_take=solve(i+1,false,prices);
        profit=max({profit,take,not_take});
    }
    return dp[i][buy]=profit;
 }
    int maxProfit(vector<int>& prices) {
     n=prices.size();
     memset(dp,-1,sizeof(dp));
     return solve(0,true,prices);
    }
};*/

//Time COmplexity: O(n)
//SPace COmplexity: O(n)
//Recursion + Memoization Approach------------
class Solution {
public:
 
    int maxProfit(vector<int>& prices) {
     int  n=prices.size();
      if(n<=1)
            return 0;
     vector<int>dp(n,0);
     dp[0]=0;
     dp[1]=max(0,prices[1]-prices[0]);
     for(int i=2;i<n;i++){
        dp[i]=dp[i-1];
       for(int j=0;j<i;j++){
          int prev=(j>=2)?dp[j-2]:0;
         dp[i]=max(dp[i],prices[i]-prices[j]+prev);
       }
        
     }
     return dp[n-1];
    }
};