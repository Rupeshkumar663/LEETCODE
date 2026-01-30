class Solution {
public:
   void DFS(vector<vector<char>>& grid,int i,int j,int &n,int &m){
     if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0')
       return ;
    grid[i][j]='0';//visited
     DFS(grid,i,j+1,n,m);//right
     DFS(grid,i,j-1,n,m);//left
     DFS(grid,i-1,j,n,m);//up
     DFS(grid,i+1,j,n,m);//down
   }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    DFS(grid,i,j,n,m);
                }
            }
        }
        return count;
    }
};