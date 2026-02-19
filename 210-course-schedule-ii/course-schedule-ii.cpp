//BY USING KAHN'S ALGORITHM----------------------------------
class Solution {
public:
   void BFS(vector<vector<int>>& adj,vector<int>&indegree,int numCourses,vector<int>& result){
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int temp=q.front();
            q.pop();
             result.push_back(temp);
            for(int &V:adj[temp]) {
                indegree[V]--;        
                if(indegree[V]==0)
                    q.push(V);
            }
        }
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++) {
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            adj[y].push_back(x);
            indegree[x]++;
        }
        vector<int>result;
        BFS(adj,indegree,numCourses,result);
        if(result.size()!=numCourses)
          return {};
        return result;
    }
};
