/*
class Solution {
public:
 //Time Complexity: O(2^n)
 //Space Complexity: O(1)
 //Recursion Approach----------
   int m,n;
   int solve(vector<vector<int>>& grid,int i,int j){
     if(i==m-1 && j==n-1){
        return grid[i][j];
     }
      if(i>=m || j>=n){
        return INT_MAX;
      }
     int right=solve(grid,i,j+1);
     int down=solve(grid,i+1,j);
     return grid[i][j]+min(right,down);
   }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        return solve(grid,0,0);
    }
};*/

//Time Complexity: O(n*n)
 //Space Complexity: O(n*n)
 //Recursion+Memoization Approach----------
class Solution {
public:

   int m,n;
    int dp[201][201];
   int solve(vector<vector<int>>& grid,int i,int j){
     if(i==m-1 && j==n-1){
        return grid[i][j];
     }
      if(i>=m || j>=n){
        return INT_MAX;
      }
      if(dp[i][j]!=-1){
        return dp[i][j];
      }
     int right=solve(grid,i,j+1);
     int down=solve(grid,i+1,j);
     return dp[i][j]=grid[i][j]+min(right,down);
   }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0);
    }
};

/*
 //Time Complexity: O(n*n)
 //Space Complexity: O(n*n)
 //Bottom-up Approach----------
 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        // state definition-------
        //dp[i][j]=minimum path sum from (0,0) to (i,j)
        dp[0][0]=grid[0][0];
        //Row filled------
        for(int i=1;i<m;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        //Column filled-------
        for(int j=1;j<n;j++){
            dp[0][j]=grid[0][j]+dp[0][j-1];
        }
        //filled rest part of dp 
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(grid[i][j]+dp[i-1][j],grid[i][j]+dp[i][j-1]);
           }
        }
        return dp[m-1][n-1];
    }
};
*/