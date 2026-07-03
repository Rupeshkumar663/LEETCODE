/*
class Solution {
public:
    int solve(string &s,int i,int j){
        if(i>=j){
            return 0;
        }
        if(s[i]==s[j]){
           return solve(s,i+1,j-1);
        }
         return 1+min(solve(s,i+1,j),solve(s,i,j-1));
    }
    int minInsertions(string s) {
        int n=s.size();
       return solve(s,0,n-1);
    }
};
*/

/*
class Solution {
public:
int dp[501][501];
    int solve(string &s,int i,int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
           return dp[i][j]=solve(s,i+1,j-1);
        }
         return dp[i][j]=1+min(solve(s,i+1,j),solve(s,i,j-1));
    }
    int minInsertions(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
       return solve(s,0,n-1);
    }
};
*/
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};