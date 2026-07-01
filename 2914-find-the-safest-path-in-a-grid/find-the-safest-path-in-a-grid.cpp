class Solution {
public:
   int n;
    vector<vector<int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
    bool Reach(vector<vector<int>>&dist,int mid){
        if(dist[0][0]<mid) 
         return false;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            if(x==n-1 && y==n-1)
                return true;
            for(auto &d:direction){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny]&& dist[nx][ny]>= mid){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                  q.push({i,j});
                  dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto&d:direction){
                int i=x+d[0];
                int j=y+d[1];
                if(i>=0 && i<n && j>=0 && j<n && dist[i][j]==-1){
                    dist[i][j]=dist[x][y]+1;
                    q.push({i,j});

                }
            }
        }
        int l=0;
        int h=2*n;
        int result=0;
        while(l<=h){
            int mid=(l+h)/2;
           if(Reach(dist,mid)){
               result=mid;
               l=mid+1;
           }else{
              h=mid-1;
           }

        }
      return result;
    }
};