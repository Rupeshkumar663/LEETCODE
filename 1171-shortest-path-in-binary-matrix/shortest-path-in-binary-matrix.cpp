class Solution {
public:
  void BFS(vector<vector<int>>& grid,int n,int &result,int a,int b){
    queue<pair<int,int>>q;
    q.push({a,b});
    grid[a][b]=1;
    while(!q.empty()){
        int x=q.size();
        while(x--){
          pair<int,int>temp=q.front();
          q.pop();
          int i=temp.first;
          int j=temp.second;
          if(i==n-1 && j==n-1)
             return;
          if((i-1)>=0 && i<n && grid[i-1][j]==0){//upward
              q.push({i-1,j});
              grid[i-1][j]=1;
           }
          if((i-1)>=0 && i<n && (j-1)>=0 && j<n && grid[i-1][j-1]==0){//left-up corner
              q.push({i-1,j-1});
              grid[i-1][j-1]=1;
           }
          if((j-1)>=0 && j<n && grid[i][j-1]==0){//left
              q.push({i,j-1});
              grid[i][j-1]=1;
          }
          if( (i+1)<n && (j-1)>=0 && grid[i+1][j-1]==0){//left-down corner
              q.push({i+1,j-1});
              grid[i+1][j-1]=1;
           }
          if( (i+1)<n && grid[i+1][j]==0){//down
              q.push({i+1,j});
              grid[i+1][j]=1;
           }
         if( (i+1)<n && (j+1)<n && grid[i+1][j+1]==0){//right-down corner
              q.push({i+1,j+1});
              grid[i+1][j+1]=1;
         }
         if(  (j+1)<n && grid[i][j+1]==0){//right
              q.push({i,j+1});
              grid[i][j+1]=1;
          }
         if( (i-1)>=0 && (j+1)<n && grid[i-1][j+1]==0){//right-up corner
              q.push({i-1,j+1});
              grid[i-1][j+1]=1;
         }
        }
        result++;
    }
    result=-1;
  }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int result=1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
           return -1;
          BFS(grid,n,result,0,0);
        return result;
    }
};