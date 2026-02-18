class Solution {
public:
 bool DFS(vector<vector<int>>&graph,int node,vector<int>&color,int currcolor){
    color[node]=currcolor;
    for(int &v:graph[node]){
        if(color[node]==color[v]){
            return false;
        }
        if(color[v]==-1){
            color[v]=1-currcolor;
           if(DFS(graph,v,color,color[v])==false)
           return false;
        }
    }
    return true;
 }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        //red=1;
        //green=0;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
               if( DFS(graph,i,color,1)==false)
                 return false;
            }
        }
        return true;
    }
};