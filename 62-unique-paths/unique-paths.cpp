//Time Complexity: O(2^(m+n))
//Space Complexity: O(1)
//Recursion-----------------------------
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
/*
//Time Complexity: O(m*n)
//Space Complexity: O(m*n)
//Recursion+Memoization------------------
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

*/
/*//Time Complexity: O(m*n)
//Space Complexity: O(m*n)
//Buttom-Up------------------
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n));
         dp[0][0]=1;
         for(int i=1;i<m;i++){
            dp[i][0]=1;
         }
         for(int j=1;j<n;j++){
            dp[0][j]=1;
         }
         for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
         }
         return dp[m-1][n-1];
    }
};


//Time Complexity: O(m*n)
//Space Complexity: O(m*n)
//Recursion Approach------------------
class Solution {
public:
  int Solve(int i,int j,int &m,int &n){
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(i==m || j==n){
        return 0;
    }
    int right=Solve(i,j+1,m,n);
    int down=Solve(i+1,j,m,n);
    return right+down;
  }
    int uniquePaths(int m, int n) {
        return Solve(0,0,m,n);
    }
};

//Time Complexity: O(m*n)
//Space Complexity: O(m*n)
//Recursion +Memoization Approach------------------
class Solution {
public:
 int dp[101][101];
  int Solve(int i,int j,int &m,int &n){
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(i==m || j==n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int right=Solve(i,j+1,m,n);
    int down=Solve(i+1,j,m,n);
    return dp[i][j]=right+down;
  }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return Solve(0,0,m,n);
    }
};
*/

/*//Time Complexity: O(m*n)
//Space Complexity: O(m*n)
//Bottom-Up Approach------------------
class Solution {
public:
 
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
         for(int j=1;j<n;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int right=dp[i][j-1];
                int down=dp[i-1][j];
                dp[i][j]=right+down;
            }
        }
        return dp[m-1][n-1];
    }
};

*/

/*//Time Complexity: O(m*n)
//Space Complexity: O(m*n)
//Bottom-Up Approach------------------
class Solution {
public:
int dp[101][101];
   int Solve(int i,int j,int &m,int &n){
      if(i==m-1 && j==n-1){
        return 1;
      }
      if(i>=m || j>=n){
        return 0;
      }
      if(dp[i][j]!=-1){
        return dp[i][j];
      }
      int right=Solve(i+1,j,m,n);
      int left=Solve(i,j+1,m,n);
      return dp[i][j]=left+right;
   }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
      return  Solve(0,0,m,n);
    }
};

*/

//Time Complexity: O(m*n)
//Space Complexity: O(m*n)
//Bottom-Up Approach------------------
class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>>dp(m+1,vector<int>(n+1,0));
      for(int i=0;i<m;i++){
        dp[i][0]=1;
      }
      for(int j=1;j<n;j++){
        dp[0][j]=1;
      }
      for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
      }
      return dp[m-1][n-1];
    }
};

