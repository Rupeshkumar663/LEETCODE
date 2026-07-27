class Solution {
public:   
   

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>result(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    result[i][j]=0;
                    q.push({i,j});
                }
            }
        }
         vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
         while(!q.empty()){
            pair<int,int>temp=q.front();
            q.pop();
            int i=temp.first;
            int j=temp.second;
            for(auto direction:dir){
                int x=i+direction[0];
                int y=j+direction[1];
                if(x>=0 && x<m && y>=0&& y<n && result[x][y]==-1){
                    result[x][y]=result[i][j]+1;
                    q.push({x,y});
                }
            }
         }
         return result;
    }
};
