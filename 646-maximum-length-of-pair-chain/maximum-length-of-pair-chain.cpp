//T.C-2^n-
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