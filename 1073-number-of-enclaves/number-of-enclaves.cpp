class Solution {
public:
  void DFS(vector<vector<int>>& grid,int i,int j,int &m,int &n){
    if(i<0 ||j<0 ||i>=m || j>=n || grid[i][j]==0)
      return;
      grid[i][j]=0;
       DFS(grid,i,j-1,m,n);//left
       DFS(grid,i,j+1,m,n);//right
       DFS(grid,i+1,j,m,n);//down
       DFS(grid,i-1,j,m,n);//up
  }
    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.size()==0)
           return 0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 &&(i==0 || j==0 || i==m-1 ||j==n-1)){
                    DFS(grid,i,j,m,n);
                }
            }
        }
        int result=0;
         for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1)
                    result++;
            }
        }
        return result;
    }
};