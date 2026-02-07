/*//APPROACH-1 BY USING DFS-----------------------------------------
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
*/
//APPROACH-2 BY USING DFS-----------------------------------------
class Solution {
public:
  void BFS(vector<vector<int>>& grid, vector<vector<int>>& temp){
    queue<vector<int>>q;

    for(int i=0;i<temp.size();i++){
        int x=temp[i][0];
        int y=temp[i][1];
        grid[x][y]=0;
        q.push({x,y});
    }

    while(!q.empty()){
        vector<int>num=q.front();
        q.pop();
        int x=num[0];
        int y=num[1];

        if(x-1>=0 && grid[x-1][y]==1){
            q.push({x-1,y});
            grid[x-1][y]=0;
        }
        if(x+1<grid.size() && grid[x+1][y]==1){
            q.push({x+1,y});
            grid[x+1][y]=0;
        }
        if(y-1>=0 && grid[x][y-1]==1){
            q.push({x,y-1});
            grid[x][y-1]=0;
        }
        if(y+1<grid[0].size() && grid[x][y+1]==1){
            q.push({x,y+1});
            grid[x][y+1]=0;
        }
    }
  }

    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.size()==0)
           return 0;

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (i==0 || j==0 || i==m-1 || j==n-1)){
                    temp.push_back({i,j});
                }
            }
        }

        BFS(grid,temp);

        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    result++;
            }
        }
        return result;
    }
};
