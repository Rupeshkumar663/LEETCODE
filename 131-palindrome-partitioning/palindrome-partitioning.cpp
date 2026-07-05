//Time complexity: O(2^n)
//Space Complexity: O(n*n)
class Solution {
public:
int n;
 void solve(string &s,int i,vector<string>&temp, vector<vector<string>>&result,vector<vector<bool>>&dp){
    if(i==n){
        result.push_back(temp);
        return;
    }
    for(int j=i;j<n;j++){
        if(dp[i][j]==true){
            temp.push_back(s.substr(i,j-i+1));
            solve(s,j+1,temp,result,dp);
            temp.pop_back();
        }
    }
 }
    vector<vector<string>> partition(string s) {
        n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,true));
        for(int i=n-1;i>=0;i--){//O(n*n)
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j] && (j-i+1)==2){
                    dp[i][j]=true;
                }
                else if(s[i]==s[j]&& dp[i+1][j-1]==true){
                    dp[i][j]=true;
                }else{
                    dp[i][j]=false;
                 }
            }
        }
      vector<string>temp;
      vector<vector<string>>result;
      solve(s,0,temp,result,dp);//O(2^n)
      return result;
    }
};