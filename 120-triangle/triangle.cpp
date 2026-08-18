/*
//Time Complexity: O(2^n)
//Space Complexity: O(1)
//Bottom-Up Approach----------
class Solution {
public:
  int n;
  int Solve(int i,int j,vector<vector<int>>& triangle){
    if(i==n-1){
        return triangle[i][j];
    }
    int current=Solve(i+1,j,triangle);
    int next=Solve(i+1,j+1,triangle);
    return triangle[i][j]+min(current,next);
  }
    int minimumTotal(vector<vector<int>>& triangle) {
         n=triangle.size();
       return  Solve(0,0,triangle);
    }
};

*/


//Time Complexity: O(n*n)
//Space Complexity: O(n*n)
//Top-Down Approach (Recursion + Memoization)

class Solution {
public:
  int n;
  vector<vector<int>>dp;
  int Solve(int i,int j,vector<vector<int>>& triangle){
    if(i==n-1){
        return triangle[i][j];
    }
    if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
    int current=Solve(i+1,j,triangle);
    int next=Solve(i+1,j+1,triangle);
    return dp[i][j]=triangle[i][j]+min(current,next);
  }
    int minimumTotal(vector<vector<int>>& triangle) {
         n=triangle.size();
         dp.assign(n,vector<int>(n,INT_MAX));
       return  Solve(0,0,triangle);
    }
};










/*
//Time Complexity: O(n*n)
//Space Complexity: O(n*n)
//Bottom-Up Approach----------
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>dp=triangle[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++)
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
            
        }
        return dp[0];
    }
};*/