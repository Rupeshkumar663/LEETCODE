//Approach-1 BY USING MAP AND DFS-------------
/*class Solution {
public:
 void dfs(unordered_map<int,vector<int>>adj,int u, vector<bool>&visited){
    visited[u]=true;
    for(int & v:adj[u]){
        if(!visited[x]){
            dfs(adj,x,visited);
        }
    }
 }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(isConnected[i][j]==1){
                adj[i].push_back(j);
                 adj[j].push_back(i);
               }
            }
        }

        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(adj,i,visited);
            }
        }
        return count;
    }
};
Approach-2 DFS AND WITHOUT USING MAP-------------

class Solution {
public:
 void dfs(vector<vector<int>>&adj,int u, vector<bool>&visited,int &n){
    visited[u]=true;
    for(int v=0;v<n;v++){
        if(adj[u][v]==1 && !visited[v]){
            dfs(adj,v,visited,n);
        }
    }
 }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(isConnected,i,visited,n);
            }
        }
        return count;
    }
};

Approach-3  USING MAP AND BFS-------------
class Solution {
public:
   void BFS( unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited){
    queue<int>q;
     q.push(u);
      visited[u]=true;
     while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto x:adj[u]){
            if(!visited[x] ){
                 visited[x]=true;
                q.push(x);
            }
        }
     }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
       unordered_map<int,vector<int>>adj;
       for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
              adj[i].push_back(j);
              adj[j].push_back(i);
            }
          }
       }
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                BFS(adj,i,visited);
                count++;
            }
        }
       return count;
    }
};

Approach-4 BFS AND USING MAP -------------
*/
/*
class Solution {
public:
   void BFS( vector<vector<int>>&adj,int u,vector<bool>&visited){
    queue<int>q;
     q.push(u);
      visited[u]=true;
     while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<adj[u].size();v++){
            if(!visited[v] && adj[u][v]==1){
                 visited[v]=true;
                q.push(v);
            }
        
     }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                BFS( isConnected,i,visited);
                count++;
            }
        }
       return count;
    }
};
*/
/*//Time Complexity: O(n*n)
//Space Complexity: O(n*n)
class Solution {
public:
  void DFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited){
    visited[u]=true;
     for(int v:adj[u]){
        if(!visited[v]){
            DFS(adj,v,visited);
        }
     }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n=isConnected.size();
       unordered_map<int,vector<int>>adj;
       for(int i=0;i<n;i++){//Time Complexity: O(n*n)
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
       }
       vector<bool>visited(n,false);
       int count=0;
       //overall Time Complexity: O(n*n)
       for(int i=0;i<n;i++){//Time Complexity: O(n)
        if(!visited[i]){
            count++;
            DFS(adj,i,visited);// DFS Approach Time Compexity: O(V+E)=O(n)
        }
       }
       return count;
    }
};*/

/*
//Time Complexity: O(n*n)
//Space Complexity: O(n*n)
class Solution {
public:
void DFS(unordered_map<int,vector<int>>&adj,int u,vector<bool> &visited){
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            DFS(adj,v,visited);
        }
    }
}
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
       unordered_map<int,vector<int>>adj(n);
       vector<bool>visited(n,false);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
         }
       }

       int count=0;
       for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            DFS(adj,i,visited);
        }
       }
       return count;
    }
};*/

//Time Complexity: O(n*n)
//Space Complexity: O(n*n)
class Solution {
public:
void DFS(vector<vector<int>>& isConnected,int u,vector<bool> &visited,int n){
    visited[u]=true;
    for(int v=0;v<n;v++){
        if(!visited[v] && isConnected[u][v]==1){
            DFS(isConnected,v,visited,n);
        }
    }
}
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n=isConnected.size();
       vector<bool>visited(n,false);
       int count=0;
       for(int i=0;i<n;i++){
        if(!visited[i]){
            count++;
            DFS(isConnected,i,visited,n);
        }
       }
       return count;
    }
};