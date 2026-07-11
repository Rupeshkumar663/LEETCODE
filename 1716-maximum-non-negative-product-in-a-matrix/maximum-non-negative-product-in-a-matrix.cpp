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