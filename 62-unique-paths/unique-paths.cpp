/*
class Solution {
public:
  int solve(int i,int j,int &m,int &n){
    if(i==m-1 && j==n-1){//if satified condtion.then return 1;
        return 1;
    }
    if(i<0 || i>=m || j<0 || j>=n){//if go out of bound then return 0
        return 0;
    }
    int right=solve(i,j+1,m,n);//it return direction of right moves
    int down=solve(i+1,j,m,n);//it return direction of down moves
    return right+down;//return total number of unique ways
  }
    int uniquePaths(int m, int n) {
       return solve(0,0,m,n);
    }
};*/
class Solution {
public:

  int solve(int i,int j,int &m,int &n, vector<vector<int>>&dp){
    if(i==m-1 && j==n-1){//if satified condtion.then return 1;
        return 1;
    }
    if(i<0 || i>=m || j<0 || j>=n){//if go out of bound then return 0
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int right=solve(i,j+1,m,n,dp);//it return direction of right moves
    int down=solve(i+1,j,m,n,dp);//it return direction of down moves
    return dp[i][j]=right+down;//return total number of unique ways
  }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
       return solve(0,0,m,n,dp);
    }
};