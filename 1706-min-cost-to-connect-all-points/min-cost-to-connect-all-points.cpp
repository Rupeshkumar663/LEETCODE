class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
         int V=points.size();
        vector<vector<pair<int,int>>>adj(V);
        int n=points.size();
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
          for(int j=i+1;j<n;j++){
            int x2=points[j][0];
            int y2=points[j][1];
            int d=abs(x1-x2)+abs(y1-y2);
            adj[i].push_back({j,d});
            adj[j].push_back({i,d});
          }
        }
       
        vector<bool>visited(V,false);
        int sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int wt=p.first;
            int node=p.second;
            if(visited[node])
              continue;
            visited[node]=true;
            sum+=wt;
            for(auto &x:adj[node]){
                int neighbour=x.first;
                int wt=x.second;
                if(!visited[neighbour]){
                    pq.push({wt,neighbour});
                }
            }
        }
        return sum;
    }
};