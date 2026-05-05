class Solution {
public:
  int find(int u,vector<int>&parent){
      if(parent[u]==u)
        return u;
    return parent[u]=find(parent[u],parent);
  }
  void union_set(int u,int v,vector<int>&parent,vector<int>&rank){
     int u_parent=find(u,parent);
     int v_parent=find(v,parent);
     if(u_parent==v_parent)
        return;
     if(rank[u_parent]>rank[v_parent]){
         parent[v_parent]=u_parent;
     } else  if(rank[u_parent]<rank[v_parent]){
         parent[u_parent]=v_parent;
     } else{
         parent[u_parent]=v_parent;
         rank[v_parent]++;
     }
  }
    int makeConnected(int n, vector<vector<int>>& connections) {
         if(connections.size()<n-1)
            return -1;
        int result=n;
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<int>rank(n,0);
        for(auto &temp:connections){
            int u=temp[0];
            int v=temp[1];
            int u_parent=find(u,parent);
            int v_parent=find(v,parent);
            if(u_parent!=v_parent){
                result--;
                union_set(u,v,parent,rank);
            }
        }
      return result-1;
    }
};