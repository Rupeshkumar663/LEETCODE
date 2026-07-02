//Time Complexity-O(m*n)
//Space Complexity-O(m*n)
class Solution {
public:
    int m,n;
    bool BFS(vector<vector<int>>& grid,int health,vector<vector<int>>& visited){
        vector<pair<int,int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        int remHealth=health-grid[0][0];
        if(remHealth<=0)
            return false;
        queue<tuple<int,int,int>>q;  
        q.push({0,0,remHealth});
        visited[0][0]=remHealth;
        while(!q.empty()){
            auto [x,y,currHealth]=q.front();
            q.pop();
            if(x==m-1 && y==n-1)
                return true;

            for(auto dir:direction){
                int nx=x+dir.first;
                int ny=y+dir.second;
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int newHealth=currHealth-grid[nx][ny];
                    if(newHealth>0 && newHealth>visited[nx][ny]){
                        visited[nx][ny]=newHealth;
                        q.push({nx,ny,newHealth});
                    }
                }
            }
        }
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,-1));
        return BFS(grid,health,visited);
    }
};