//Time Complexity: O(n*m)
//Space Complexity: O(n*m)
class Solution {
public:
int n,m;
int dp[1001][1001];
   int Solve(int i,int j,string &s, string &t){
    if(j==m){
        return 1;
    }
    if(i==n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int take=0;
    if(s[i]==t[j]){
      take=Solve(i+1,j+1,s,t);
    }
    int skip=Solve(i+1,j,s,t);
    return dp[i][j]=take+skip;
   }
    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        memset(dp,-1,sizeof(dp));
       return Solve(0,0,s,t); 
    }
};