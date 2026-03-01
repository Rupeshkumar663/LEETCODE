//DFS-APROACH----------------------------------
/*
class Solution{
public:
void DFS(unordered_map<int,vector<pair<int,int>>>&adj,int&src,int&dst,int&k,vector<bool>&visited,int&result,int cost){
 if(k<-1)
  return;
  if(src==dst){
    result=min(result,cost);
    return;
   }
   visited[src]=true;
   for(auto x:adj[src]){
      int v=x.first;
      int price=x.second;
     if(!visited[v]&&cost+price<result){
     int nk=k-1;
     DFS(adj,v,dst,nk,visited,result,cost+price);
    }
  }
  visited[src]=false;
 }
int findCheapestPrice(int n,vector<vector<int>>&flights,int src,int dst,int k){
   unordered_map<int,vector<pair<int,int>>>adj;
   for(auto flight:flights){
    int u=flight[0];
    int v=flight[1];
    int price=flight[2];
    adj[u].push_back({v,price});
   }
  vector<bool>visited(n,false);
   int result=INT_MAX;
   DFS(adj,src,dst,k,visited,result,0);
   return result==INT_MAX?-1:result;
  }
};
*/
//Approach-1 (BFS)
//T.C : O(V+E) - BFS traversal of Graph
//S.C : O(V+E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>distance(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int>&vec:flights) {
            int u=vec[0];
            int v=vec[1];
            int cost=vec[2];
            adj[u].push_back({v,cost});
        }
        queue<pair<int,int>> que;
        que.push({src,0});
        distance[src]=0;
        int level=0;
        while(!que.empty()&&level<=k) {
            int N=que.size();
            while(N--) {
                int u=que.front().first;
                int d=que.front().second;
                que.pop();
                for(pair<int,int>&P:adj[u]) {
                    int v=P.first;
                    int cost=P.second;
                    if(distance[v]>d+cost) {
                        distance[v]=d+cost;
                        que.push({v,d+cost});
                    }
                }
            }
            level++;
        }
        return distance[dst]==INT_MAX?-1:distance[dst];
    }
};