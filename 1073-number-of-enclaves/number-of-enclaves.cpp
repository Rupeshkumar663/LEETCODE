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
        
         // top & bottom row
        for(int j=0;j<n;j++){
            if(grid[0][j]==1)
             DFS(grid,0,j,m,n);
            if(grid[m-1][j]==1)
             DFS(grid,m-1,j,m,n);
        }

        // left & right column
        for(int i=0;i<m;i++){
            if(grid[i][0]==1)
             DFS(grid,i,0,m,n);
            if(grid[i][n-1]==1)
             DFS(grid,i,n-1,m,n);
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