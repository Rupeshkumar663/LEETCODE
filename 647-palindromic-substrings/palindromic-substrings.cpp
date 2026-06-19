/*
//T.C-O(n^3)---------
//Brute force Approach---------
class Solution {
public:
   bool check(string &s,int i,int j){
    if(i>j){
        return true;
    }
    if(s[i]==s[j]){
        return check(s,i+1,j-1);
    }
   return false; 
   }
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)==true){
                    count++;
                }
            }
        }
        return count;
    }
};
*/

//T.C-O(n^2)---------
//Memoization Approach---------
/*
class Solution {
public:
  int dp[1001][1001];
   bool check(string &s,int i,int j){
    if(i>j){
        return true;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==s[j]){
        return dp[i][j]=check(s,i+1,j-1);
    }
   return dp[i][j]=false; 
   }
    int countSubstrings(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s,i,j)==true){
                    count++;
                }
            }
        }
        return count;
    }
};*/
//T.C-O(n^2)---------
//S.C-O(n^2)---------
//Blue print(Bottom-up) Approach--------
class Solution {
public:
  
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int count=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j){
                    dp[i][j]=true;
                } else if(i+1==j){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                }
                if(dp[i][j]==true){
                    count++;
                }
            }
        }
        return count;
    }
};