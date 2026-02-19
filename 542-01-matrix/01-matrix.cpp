class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(mat[i][j]==0)
                    q.push({i,j}),dist[i][j]=0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto p=q.front();q.pop();
            for(int k=0;k<4;k++){
                int nx=p.first+dx[k],ny=p.second+dy[k];
                if(nx>=0&&ny>=0&&nx<m&&ny<n&&dist[nx][ny]==-1)
                    dist[nx][ny]=dist[p.first][p.second]+1,
                    q.push({nx,ny});
            }
        }
        return dist;
    }
};
