class Solution {
public:
 bool DFS( unordered_map<int,vector<int>>&adj,int u,vector<bool>& hasApple,vector<bool>visited,int &result){
  visited[u]=true;
  bool foundApple=hasApple[u];
  for(int &v:adj[u]){
    if(!visited[v]){
      if(DFS(adj,v,hasApple,visited,result)){
         result+=2;//go+come back
         foundApple=true;
      }
     }
   }
   return foundApple;
 }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       vector<bool>visited(n,false);
       int result=0;
       DFS(adj,0,hasApple,visited,result);
       return result;
    }
};