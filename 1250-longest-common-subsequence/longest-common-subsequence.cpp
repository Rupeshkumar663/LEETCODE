//Recursion
//T.C-O(2^(m+n))
/*
class Solution {
public:
int m,n;
int solve(string &text1, string &text2,int i,int j){
    if(i>=m || j>=n){
        return 0;
    }
    if(text1[i]==text2[j]){
        return 1+solve(text1,text2,i+1,j+1);
    } else{
        return max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size();
        n=text2.size();
       return solve(text1,text2,0,0);
    }
};*/
//Recursion+memoization
//T.C-O(m*n)
//S.C-O(m*n)
/*

class Solution {
public:
int m,n;
int dp[1001][1001];
int solve(string &text1, string &text2,int i,int j){
    if(i>=m || j>=n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i]==text2[j]){
        return dp[i][j]=1+solve(text1,text2,i+1,j+1);
    } else{
        return dp[i][j]=max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        m=text1.size();
        n=text2.size();
        memset(dp,-1,sizeof(dp));
       return solve(text1,text2,0,0);
    }
};*/
//Buttom-Up
//T.C-O(m*n)
//S.C-O(m*n)
/*

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
       for(int row=0;row<m+1;row++){
         dp[row][0]=0;
       }
       for(int col=0;col<n+1;col++){
         dp[0][col]=0;
       }

       for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            } else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
         }
       }
       return dp[m][n];
    }
};
*/
//PRINT LONGEST COMMON SUBSEQUENCE----------------------

/*class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
       for(int row=0;row<m+1;row++){
         dp[row][0]=0;
       }
       for(int col=0;col<n+1;col++){
         dp[0][col]=0;
       }
       int i,j;
       for(i=1;i<m+1;i++){
        for(j=1;j<n+1;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            } else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
         }
       }
       //i=5
       //j=3
      string result="";
      while(i>0 && j>0){
         if(text1[i-1]==text2[j-1]){
               result.push_back(text1[i-1]);
               i--;
               j--;
            } else{
                 if(dp[i][j-1]>dp[i-1][j]){
                    j--;
                 } else{
                    i--;
                 }
            }
      }
      reverse(result.begin(),result.end());
      return result;
    }
};*/

class Solution {
public:
int dp[1001][1001];
int Solve(int i,int j,string &text1, string &text2){
    //Base Case--------
    if(i==text1.size() ||j==text2.size()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i]==text2[j]){
      return dp[i][j]=1+Solve(i+1,j+1,text1,text2);
    }
    else{
       return  dp[i][j]=max(Solve(i+1,j,text1,text2),Solve(i,j+1,text1,text2));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
      return Solve(0,0,text1,text2);
    }
};