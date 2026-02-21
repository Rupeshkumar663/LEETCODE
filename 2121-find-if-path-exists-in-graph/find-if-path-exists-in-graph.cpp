class Solution {
public:
 bool DFS(vector<vector<int>>&adj,int & source,int & destination,vector<bool>&visited){
    visited[source]=true;
    if(source==destination)
        return true;

     for(int &v :adj[source]){
        if(!visited[v]){
           if( DFS(adj,v,destination,visited))
            return true;
        }
     }
     return false;
 }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        if(DFS(adj,source,destination,visited)==false)
          return false;
        return true;
    }
};