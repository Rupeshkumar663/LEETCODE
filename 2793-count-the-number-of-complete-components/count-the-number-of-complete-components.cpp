class Solution {
public:
void DFS(unordered_map<int,vector<int>>&adj,int u, vector<bool>&visited,int &nodes,int &edge){
    visited[u]=true;
    nodes++;
    edge+=adj[u].size();
    for(int i:adj[u]){
        if(!visited[i]){
            DFS(adj,i,visited,nodes,edge);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
            for(auto x:edges){
                adj[x[0]].push_back(x[1]);
                adj[x[1]].push_back(x[0]);
            }
        vector<bool>visited(n,false);
        int result=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int nodes=0;
                int edge=0;
                DFS(adj,i,visited,nodes,edge);
                edge=edge/2;
                if(edge==nodes*(nodes-1)/2){
                    result++;
                }
            }
        }
        return result;
    }
};