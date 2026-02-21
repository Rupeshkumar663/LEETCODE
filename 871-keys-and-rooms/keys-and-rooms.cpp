//BY USING DFS------------------------------------
/*
class Solution {
public:
int count=1;
  void DFS(vector<vector<int>>& rooms,int u,vector<bool>&visited){
    if(rooms.size()==count){
        return;
    }
     visited[u]=true;
       for(int &v:rooms[u]){
        if(!visited[v]){
           DFS(rooms,v,visited); 
             count++;
          }
       }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
       DFS(rooms,0,visited);
        for(int i=0;i<n;i++){
         if(visited[i]==false)
             return false;
        }
        return true;
    }
};
*/
//BY USING BFS-----------------------------

class Solution {
public:

  void BFS(vector<vector<int>>& rooms,int u,vector<bool>&visited){
     queue<int>q;
     q.push(u);
     visited[u]=true;
     while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int &v:rooms[temp]){
            if(!visited[v]){
                q.push(v);
                visited[v]=true;
            }
        }
     }

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
       BFS(rooms,0,visited);
        for(int i=0;i<n;i++){
         if(visited[i]==false)
             return false;
        }
        return true;
    }
};