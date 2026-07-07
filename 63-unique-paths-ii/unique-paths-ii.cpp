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
/*
//Time COmplexity: O(m*n)
//Space Complexity: O(m*n)
//Recursion+Memoization-----------------
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
*/

//Time COmplexity: O(m*n)
//Space Complexity: O(m*n)
//Recursion+Memoization-----------------
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int  m=obstacleGrid.size();
      int n=obstacleGrid[0].size();
      if(obstacleGrid[m-1][n-1]==1){
        return 0;
       }
      vector<vector<int>>dp(m,vector<int>(n));
      dp[0][0]=1;
      // 1st row filled-----------
      for(int j=1;j<n;j++){
        if(obstacleGrid[0][j]==1){
            dp[0][j]=0;
        }
        else if(j>=1 && obstacleGrid[0][j-1]==1){
            dp[0][j]=0;
            obstacleGrid[0][j]=1;
        }else{
            dp[0][j]=1;
        }
      }
       //1st column filled-----------
       for(int i=1;i<m;i++){
        if(obstacleGrid[i][0]==1){
            dp[i][0]=0;
        }
        else if(i>=1 && obstacleGrid[i-1][0]==1){
            dp[i][0]=0;
            obstacleGrid[i][0]=1;
        }else{
            dp[i][0]=1;
        }
      }

      //rest part will be filled----------
       for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(obstacleGrid[i][j]==1){
                dp[i][j]=0;
            }else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
       }
       return dp[m-1][n-1];
    }
};