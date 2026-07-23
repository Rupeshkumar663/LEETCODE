

class Solution {
public:
  
    int orangesRotting(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2)
                q.push({i,j});
        }
    }
    int result=0;
    while(!q.empty()){
        int t=q.size();
        while(t--){
         pair<int,int>p=q.front();
         q.pop();
         int i=p.first;
         int j=p.second;
         if(i-1>=0 && grid[i-1][j]==1){//upward
             grid[i-1][j]=2;
            q.push({i-1,j});
         }
         if(i+1<m && grid[i+1][j]==1){//downward
             grid[i+1][j]=2;
            q.push({i+1,j});
         }
         if(j-1>=0 && grid[i][j-1]==1){//left
            grid[i][j-1]=2;
            q.push({i,j-1});
         }
         if(j+1<n && grid[i][j+1]==1){//right
            grid[i][j+1]=2;
            q.push({i,j+1});
          }
        }
       result++;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 )
                return -1;
        }
    }
    return result==0?result:result-1;
  }
};
