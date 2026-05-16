//T.C-O(2^n)
//S.c-O(1)
//Recusrion Approach-
/*
class Solution {
public:
int n;
  int solve(int idx,int prev,vector<vector<int>>&pairs){
    if(idx>=n){
        return 0;
    }
    int skip=solve(idx+1,prev,pairs);
    int take=0;
    if(prev==-1 || pairs[idx][0]>pairs[prev][1]){
        take=1+solve(idx+1,idx,pairs);
    }
    return max(skip,take);
  }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        sort(pairs.begin(),pairs.end());
        return solve(0,-1,pairs);
    }
};
*/
//T.C-O(2^n)
//S.c-O(n)
//Recusrion +memoization Approach-
/*
class Solution {
public:
int n;
  int dp[1001][1001];
  int solve(int idx,int prev,vector<vector<int>>&pairs){
    if(idx>=n){
        return 0;
    }
    if(dp[idx][prev+1]!=-1){
        return dp[idx][prev+1];
    }
    int skip=solve(idx+1,prev,pairs);
    int take=0;
    if(prev==-1 || pairs[idx][0]>pairs[prev][1]){
        take=1+solve(idx+1,idx,pairs);
    }
    return dp[idx][prev+1]=max(skip,take);
  }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        return solve(0,-1,pairs);
    }
};
*/
class Solution {
public:

 
    int findLongestChain(vector<vector<int>>& pairs) {
       int n=pairs.size();
       vector<int>dp(n,1);
        sort(pairs.begin(),pairs.end());
        int result=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                result=max(result,dp[i]);
            }
        }
        return result;
    }
};