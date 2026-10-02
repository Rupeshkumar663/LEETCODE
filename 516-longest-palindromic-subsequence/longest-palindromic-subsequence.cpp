/*class Solution {
public:
   int n;
   bool check(string &temp){
    int i=0;
    int j=temp.size()-1;
    while(i<j){
         if(temp[i]!=temp[j])
           return false;
           i++;
           j--;
    }
    return true;
   }
    int Solve(int i,string temp,string &s){
        if(i==n){
            if(check(temp))
                return temp.size();
            return 0;
        }
        string t=temp;
        t.push_back(s[i]);
        int take=Solve(i+1,t,s);
        int skip=Solve(i+1,temp,s);
        return max(take,skip);
    }
    int longestPalindromeSubseq(string s) {
       n=s.size();
       return Solve(0,"",s); 
    }
};*/

class Solution {
public:
int dp[1001][1001];
  int Solve(int i,int j,string &s){
    if(j<i){
        return 0;
    }
    if(i==j){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int take=0;
    if(s[i]==s[j]){
        take=2+Solve(i+1,j-1,s);
    }
    int skip=max(Solve(i+1,j,s),Solve(i,j-1,s));
    return dp[i][j]= max(take,skip);
    //return dp[i][j]=max(Solve(i+1,j,s),Solve(i,j-1,s));
  }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return Solve(0,n-1,s);
    }
};