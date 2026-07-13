class Solution {
public:
 //Time Complexity: O(n*n)
 //Space Complexity: O(n*n)
 //Brute force Approach----------
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