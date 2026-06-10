/*
class Solution {
public:
int m,n;
int solve(string word1, string word2,int i,int j){
    if(i==m){
        return n-j;
    }
    if(j==n){
        return m-i;
    }
    if(word1[i]==word2[j]){
        return solve(word1,word2,i+1,j+1);
    } else{
       int insert=1+solve(word1,word2,i,j+1);
       int deletes=1+solve(word1,word2,i+1,j);
       int replace=1+solve(word1,word2,i+1,j+1);
       return min({insert,deletes,replace});
    }
}
    int minDistance(string word1, string word2) {
        m=word1.length();
        n=word2.length();
       return solve(word1,word2,0,0);
    }
};
*/
/*

class Solution {
public:
int m,n;
int dp[501][501];
int solve(string word1, string word2,int i,int j){
    if(i==m){
        return n-j;
    }
    if(j==n){
        return m-i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(word1[i]==word2[j]){
       return dp[i][j]=solve(word1,word2,i+1,j+1);
    } else{
       int insert=1+solve(word1,word2,i,j+1);
       int deletes=1+solve(word1,word2,i+1,j);
       int replace=1+solve(word1,word2,i+1,j+1);
      return dp[i][j]=min({insert,deletes,replace});
    }

}
    int minDistance(string word1, string word2) {
        m=word1.length();
        n=word2.length();
        memset(dp,-1,sizeof(dp));
       return solve(word1,word2,0,0);
    }
};*/


class Solution {
public:
int m,n;
int dp[501][501];
int solve(string word1, string word2,int i,int j){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(word1[i]==word2[j]){
       return dp[i][j]=solve(word1,word2,i-1,j-1);
    } else{
       int insert=1+solve(word1,word2,i,j-1);
       int deletes=1+solve(word1,word2,i-1,j);
       int replace=1+solve(word1,word2,i-1,j-1);
      return dp[i][j]=min({insert,deletes,replace});
    }

}
    int minDistance(string word1, string word2) {
        m=word1.length();
        n=word2.length();
        memset(dp,-1,sizeof(dp));
       return solve(word1,word2,m-1,n-1);
    }
};