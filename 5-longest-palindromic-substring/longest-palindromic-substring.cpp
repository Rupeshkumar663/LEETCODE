/*
class Solution {
public:
int n;
   bool palindrome(string & s,int i,int j){
    if(i>=j){
        return true;
    }
    if(s[i]==s[j]){
        return palindrome(s,i+1,j-1);
    }else{
        return false;
    }
    return false;
  }
    string longestPalindrome(string s) {
      n=s.size();
      int maxlength=0;
      int sp=-1;
      for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(palindrome(s,i,j)==true){
                if(maxlength<j-i+1){
                    maxlength=j-i+1;
                    sp=i;
                }
            }
        }
      }  
      return s.substr(sp,maxlength);
    }
};
*/

class Solution {
public:
int n;
   int dp[1001][1001];
   bool palindrome(string & s,int i,int j){
    if(i>=j){
        return true;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==s[j]){
        return dp[i][j]=palindrome(s,i+1,j-1);
    }else{
        return dp[i][j]= false;
    }
    return dp[i][j]=false;
  }
    string longestPalindrome(string s) {
      n=s.size();
      memset(dp,-1,sizeof(dp));
      int maxlength=0;
      int sp=-1;
      for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(palindrome(s,i,j)==true){
                if(maxlength<j-i+1){
                    maxlength=j-i+1;
                    sp=i;
                }
            }
        }
      }  
      return s.substr(sp,maxlength);
    }
};