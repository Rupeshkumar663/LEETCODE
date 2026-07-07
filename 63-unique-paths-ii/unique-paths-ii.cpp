/*
//Time COmplexity: O(2^(m+n))
//Space Complexity: O(1)
//Recursion-----------------
class Solution {
public:
 int m,n;
   int solve(vector<vector<int>>& obstacleGrid,int i,int j){
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(i<0 || i>=m || j<0 || j>=n || obstacleGrid[i][j]==1){
        return 0;
     }
     int right=solve(obstacleGrid,i,j+1);
     int down=solve(obstacleGrid,i+1,j);
     return right+down;
   }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       m=obstacleGrid.size();
       n=obstacleGrid[0].size();
       if(obstacleGrid[m-1][n-1]==1){
        return 0;
       }
       return  solve(obstacleGrid,0,0);
    }
};
*/
//Time COmplexity: O(2^(m+n))
//Space Complexity: O(1)
//Recursion-----------------
class Solution {
public:
 int m,n;
 int dp[101][101];
   int solve(vector<vector<int>>& obstacleGrid,int i,int j){
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(i<0 || i>=m || j<0 || j>=n || obstacleGrid[i][j]==1){
        return 0;
     }
     if(dp[i][j]!=-1){
        return dp[i][j];
     }
     int right=solve(obstacleGrid,i,j+1);
     int down=solve(obstacleGrid,i+1,j);
     return dp[i][j]=right+down;
   }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       m=obstacleGrid.size();
       n=obstacleGrid[0].size();
       if(obstacleGrid[m-1][n-1]==1){
        return 0;
       }
       memset(dp,-1,sizeof(dp));
       return  solve(obstacleGrid,0,0);
    }
};