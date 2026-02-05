

class Solution {
public:
  void DFS(vector<vector<int>>& grid ,int i,int j,int m,int n,int count){
    if(i<0 || j<0 || i>=m|| j>=n)
        return;

    if(grid[i][j]==0)
       return ;
    
    if(grid[i][j]!=1 && grid[i][j]<2+count){
        return ;
     }
     grid[i][j]=2+count;

      DFS(grid,i,j-1,m,n,count+1);//left
      DFS(grid,i,j+1,m,n,count+1);//right
      DFS(grid,i-1,j,m,n,count+1);//up
      DFS(grid,i+1,j,m,n,count+1);//down
   }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2)
               DFS(grid,i,j,m,n,0);
         }
       } 
      
       int result=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)
               return -1;

            if(grid[i][j]>=2)
               result=max(result,grid[i][j]-2);
          }
       } 
       return result;
  }
};
