/*
class Solution {
public:
int m,n;
  int solve(string str1, string str2,int i,int j){
    if(i==0){
        return j;
    } 
    if(j==0){
        return i;
    }
    if(str1[i]==str2[j]){
        return 1+solve(str1,str2,i-1,j-1);
    } else{
        return 1+min(solve(str1,str2,i-1,j),solve(str1,str2,i,j-1));
    }
    return 0;
  }
    string shortestCommonSupersequence(string str1, string str2){
        m=str1.length();
        n=str2.length();
        return solve(str1,str2,m-1,n-1);
    }
};*/

/*
class Solution {
public:
int m,n;
int dp[1001][1001];
  int solve(string str1, string str2,int i,int j){
    if(i==0){
        return j;
    } 
    if(j==0){
        return i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(str1[i]==str2[j]){
       return dp[i][j]=1+solve(str1,str2,i-1,j-1);
    } else{
       return dp[i][j]=1+min(solve(str1,str2,i-1,j),solve(str1,str2,i,j-1));
    }
    return 0;
  }
    string shortestCommonSupersequence(string str1, string str2){
        m=str1.length();
        n=str2.length();
        memset(dp,-1,sizeof(dp));
        return solve(str1,str2,m-1,n-1);
    }
};


class Solution {
public:
int m,n;
int dp[1001][1001];
  int solve(string str1, string str2,int i,int j){
    if(i==0){
        return j;
    } 
    if(j==0){
        return i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(str1[i]==str2[j]){
       return dp[i][j]=1+solve(str1,str2,i-1,j-1);
    } else{
       return dp[i][j]=1+min(solve(str1,str2,i-1,j),solve(str1,str2,i,j-1));
    }
    return 0;
  }
    string shortestCommonSupersequence(string str1, string str2){
        m=str1.length();
        n=str2.length();
        memset(dp,-1,sizeof(dp));
        return solve(str1,str2,m-1,n-1);
    }
};
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2){
       int  m=str1.length();
       int n=str2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        int i,j;
        for( i=0;i<m+1;i++){
            for( j=0;j<n+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=i+j;
                }
                else if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        i=m;
        j=n;
        string result="";
       while(i>0 && j>0){
          if(str1[i-1]==str2[j-1]){
            result.push_back(str1[i-1]);
            i--;
            j--;
          } else{
             if(dp[i-1][j]>dp[i][j-1]){
                result.push_back(str2[j-1]);
                j--;
             } else{
                 result.push_back(str1[i-1]);
                  i--;
             }
          }
       }
       while(j>0){
         result.push_back(str2[j-1]);
         j--;
       }
        while(i>0){
         result.push_back(str1[i-1]);
         i--;
       }
       reverse(result.begin(),result.end());
       return result;
    }
};