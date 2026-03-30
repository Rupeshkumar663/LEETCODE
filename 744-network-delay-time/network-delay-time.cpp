
/*
T.C-O(V+E) BY USING BFS---------------------------------------------
class Solution {
public:
void BFS(vector<vector<pair<int,int>>>&adj, vector<int>&dist,int k){
      queue<int>q;
      q.push(k);
      dist[k]=0;
      while(!q.empty()){
        int u=q.front();
         q.pop();
         for(auto &v:adj[u]){
         int V=v.first;
         int W=v.second;
          if(dist[u]+W<dist[V]){
          dist[V]=dist[u]+W;
          q.push(V);
        }
      }
   }
 }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
       vector<int>dist(n+1,INT_MAX);
       int result=0;
        BFS(adj,dist,k);

        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)
               return -1;
          result=max(result,dist[i]);
        }
       return result;
    }
};
*/

//T.C-O((V+E)log V)
//S.C-O(V+E)
class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>result(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        result[k]=0;
        while(!pq.empty()){
            pair<int,int>temp=pq.top();
             pq.pop();
             int V=temp.second;
             int W=temp.first;
             for(auto & x:adj[V]){
                int w=x.second;
                int v=x.first;
                  if(result[v]>w+W){
                    result[v]=w+W;
                    pq.push({result[v],v});
                  }

             }
          }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(result[i]==INT_MAX)
              return -1;
            ans=max(ans,result[i]);
        }
    return ans;
    }
};