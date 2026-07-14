//Time Complexity: O(2^(m*n))
//Space Complexity: O(1)
//Recursion-----------
/*
class Solution {
public:
int m,n;
  typedef long long ll;
  long long MOD=1e9+7;
   pair<ll,ll> solve(vector<vector<int>>& grid,int i,int j){
     if(i==m-1 && j==n-1){
        return {grid[i][j],grid[i][j]};
     }

     ll maxi=LLONG_MIN;//maxi=-infinite
     ll mini=LLONG_MAX;

     //down
     if(i+1<m){
        auto [downmax,downmin]=solve(grid,i+1,j);
          maxi=max({maxi,grid[i][j]*downmax,grid[i][j]*downmin});//64
          mini=min({mini,grid[i][j]*downmax,grid[i][j]*downmin});//-96
     }
     //right
     if(j+1<n){
        auto [rightmax,rightmin]=solve(grid,i,j+1);
          maxi=max({maxi,grid[i][j]*rightmax,grid[i][j]*rightmin});//64
          mini=min({mini,grid[i][j]*rightmax,grid[i][j]*rightmin});//-96
     }
     return {maxi,mini};
   }
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        //pair<long long ,long long>p=solve(grid,0,0);
        //return p.first;
        auto [maxprod,minprod]=solve(grid,0,0);
        return maxprod<0 ? -1 : maxprod % MOD;
    }
};
*/
//Time Complexity: O(m*n)
//Space Complexity: O(m*n)
//Recursion+Memoization-----------
/*
class Solution {
public:
int m,n;
  typedef long long ll;
  long long MOD=1e9+7;
  vector<vector<pair<ll,ll>>>dp;
   pair<ll,ll> solve(vector<vector<int>>& grid,int i,int j){
     if(i==m-1 && j==n-1){
        return {grid[i][j],grid[i][j]};
     }
     if(dp[i][j]!=make_pair(LLONG_MIN,LLONG_MAX)){
        return dp[i][j];
     }
     ll maxi=LLONG_MIN;//maxi=-infinite
     ll mini=LLONG_MAX;

     //down
     if(i+1<m){
        auto [downmax,downmin]=solve(grid,i+1,j);
          maxi=max({maxi,grid[i][j]*downmax,grid[i][j]*downmin});//64
          mini=min({mini,grid[i][j]*downmax,grid[i][j]*downmin});//-96
     }
     //right
     if(j+1<n){
        auto [rightmax,rightmin]=solve(grid,i,j+1);
          maxi=max({maxi,grid[i][j]*rightmax,grid[i][j]*rightmin});//64
          mini=min({mini,grid[i][j]*rightmax,grid[i][j]*rightmin});//-96
     }
     return dp[i][j]={maxi,mini};
   }
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        //pair<long long ,long long>p=solve(grid,0,0);
        //return p.first;
        dp=vector<vector<pair<ll,ll>>>(m,vector<pair<ll,ll>>(n,{LLONG_MIN,LLONG_MAX}));
        auto [maxprod,minprod]=solve(grid,0,0);
        return maxprod<0 ? -1 : maxprod % MOD;
    }
};
*/
//Time Complexity: O(m*n)
//Space Complexity: O(m*n)
//Bottom-Up-----------
class Solution {
public:
int m,n;
  typedef long long ll;
  long long MOD=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<pair<ll,ll>>>dp(m,vector<pair<ll,ll>>(n));
        dp[0][0]={grid[0][0],grid[0][0]};
        //Column filled--------------
        for(int j=1;j<n;j++){
            dp[0][j]={dp[0][j-1].first*grid[0][j],dp[0][j-1].second*grid[0][j]};
        }

        //row filled--------------
        for(int i=1;i<m;i++){
            dp[i][0]={dp[i-1][0].first*grid[i][0],dp[i-1][0].second*grid[i][0]};
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                ll upmax=dp[i-1][j].first*grid[i][j];
                ll upmin=dp[i-1][j].second*grid[i][j];
                ll leftmax=dp[i][j-1].first*grid[i][j];
                ll leftmin=dp[i][j-1].second*grid[i][j];
                ll allmax=max({upmax,upmin,leftmax,leftmin});
                ll allmin=min({upmax,upmin,leftmax,leftmin});
                dp[i][j].first=allmax;
                dp[i][j].second=allmin;
            }
        }
        ll maxproduct=dp[m-1][n-1].first;
        if(maxproduct<0){
            return -1;
        }
        return maxproduct%MOD;
    }
};