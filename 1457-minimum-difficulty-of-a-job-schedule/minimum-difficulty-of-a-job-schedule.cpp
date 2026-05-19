//Recursion----
/*
class Solution {
public:
 int n;
  int solve(int idx,int d,vector<int>& jobDifficulty){
   if(d==1){
    int maxi=0;
    for(int i=idx;i<n;i++){
        maxi=max(maxi,jobDifficulty[i]);
    }
    return maxi;
   }
    int maxi=0;
    int finalresult=INT_MAX;
    for(int i=idx;i<=n-d;i++){
      maxi=max(maxi,jobDifficulty[i]);
     int result=maxi+solve(i+1,d-1,jobDifficulty);
      finalresult=min(finalresult,result);
    }
    return finalresult;
  }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        if(n<d){
            return -1;
        }
       return solve(0,d,jobDifficulty);
    }
};
*/

class Solution {
public:
 int n;
 int dp[3001][11];
  int solve(int idx,int d,vector<int>& jobDifficulty){
   if(d==1){
    int maxi=0;
    for(int i=idx;i<n;i++){
        maxi=max(maxi,jobDifficulty[i]);
    }
    return maxi;
   }
   if(dp[idx][d]!=-1){
    return dp[idx][d];
   }
    int maxi=0;
    int finalresult=INT_MAX;
    for(int i=idx;i<=n-d;i++){
      maxi=max(maxi,jobDifficulty[i]);
     int result=maxi+solve(i+1,d-1,jobDifficulty);
      finalresult=min(finalresult,result);
    }
    return dp[idx][d]=finalresult;
  }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        if(n<d){
            return -1;
        }
       memset(dp,-1,sizeof(dp));
       return solve(0,d,jobDifficulty);
    }
};