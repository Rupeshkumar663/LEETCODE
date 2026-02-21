class Solution {
public:
bool BFS(vector<vector<int>>&adj,int u, vector<int>&color,int currcolor){
    queue<int>q;
    q.push(u);
    color[u]=currcolor;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int &v:adj[temp]){
            if(color[v]==-1){
                q.push(v);
                color[v]=1-color[temp];
              }
            else if(color[v]==color[temp])
               return false;
        }
    }
   return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int red=0;
        int green=1;
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
          if(color[i]==-1){
            if(!BFS(adj,i,color,0))
                return false;
          }
        }

      return true;
    }
};