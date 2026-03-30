class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        vector<int>dx={0,0,1,-1};
        vector<int>dy ={1,-1,0,0};
        while(!pq.empty()) {
            auto [effort,cell]=pq.top();
            pq.pop();
            int x=cell.first;
            int y=cell.second;
            if(x==n-1 && y==m-1)
                return effort;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<m) {
                    int newEffort=max(effort,abs(heights[x][y]-heights[nx][ny]));
                    if(newEffort<dist[nx][ny]) {
                        dist[nx][ny]=newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};