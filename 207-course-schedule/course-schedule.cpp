class Solution {
public:

    bool BFS(vector<vector<int>>& adj,vector<int>&indegree,int numCourses){
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            count++;
            for(int &V:adj[temp]) {
                indegree[V]--;        
                if(indegree[V]==0)
                    q.push(V);
            }
        }
        return count==numCourses;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++) {
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            adj[y].push_back(x);
            indegree[x]++;
        }
        if(BFS(adj,indegree,numCourses)==false)
          return false;
        return true;
    }
};
