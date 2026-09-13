/*//TIme COmplexity: O(3^n)
//Space Complexity: O(1)
//Recursion------------
class Solution {
public:
  int m,n;
  int Solve(int i,int j,vector<vector<int>>&matrix){
    if(i==n-1){
        return matrix[i][j];
    }
    int down=INT_MAX;
    if((i+1)<m){
      down=matrix[i][j]+Solve(i+1,j,matrix);
    }
    int diagonal_left=INT_MAX;
    if((i+1)<m && (j-1)>=0){
      diagonal_left=matrix[i][j]+Solve(i+1,j-1,matrix);
    }
    int diagonal_right=INT_MAX;
    if((i+1)<m && (j+1)<n){
      diagonal_right=matrix[i][j]+Solve(i+1,j+1,matrix);
    }
    return min({down,diagonal_left,diagonal_right});
  }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        int result=INT_MAX;
        for(int j=0;j<n;j++){
            result=min(result,Solve(0,j,matrix));
        }
        return result;
    }
};*/


//TIme COmplexity: O(n*n)
//Space Complexity: O(n*n)
//Recursion------------
class Solution {
public:
  int m,n;
  int dp[101][101];
  int Solve(int i,int j,vector<vector<int>>&matrix){
    if(i==m-1){
        return matrix[i][j];
    }
    if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
    int down=INT_MAX;
    if((i+1)<m){
      down=matrix[i][j]+Solve(i+1,j,matrix);
    }
    int diagonal_left=INT_MAX;
    if((i+1)<m && (j-1)>=0){
      diagonal_left=matrix[i][j]+Solve(i+1,j-1,matrix);
    }
    int diagonal_right=INT_MAX;
    if((i+1)<m && (j+1)<n){
      diagonal_right=matrix[i][j]+Solve(i+1,j+1,matrix);
    }
    return dp[i][j]=min({down,diagonal_left,diagonal_right});
  }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
             dp[i][j]=INT_MAX;
           }
        }
        int result=INT_MAX;
        for(int j=0;j<n;j++){
            result=min(result,Solve(0,j,matrix));
        }
        return result;
    }
};