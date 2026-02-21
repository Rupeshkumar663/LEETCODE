class Solution {
public:

void BFS(vector<vector<char>>& maze, vector<int>& entrance,
         vector<vector<int>>&temp,int &count){

    int n=maze.size();
    int m=maze[0].size();

    queue<vector<int>>q;
    vector<vector<int>>visited(n,vector<int>(m,0));

    for(int i=0;i<temp.size();i++){
        q.push(temp[i]);
        visited[temp[i][0]][temp[i][1]]=1;
    }

    vector<int>dx={0,0,-1,1};
    vector<int>dy={-1,1,0,0};

    while(!q.empty()){
        int n=q.size(); 
        while(n--){
            vector<int>nums=q.front();
            q.pop();

            int x=nums[0];
            int y=nums[1];

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && ny>=0 &&
                   nx<maze.size() && ny<maze[0].size() &&
                   maze[nx][ny]=='.' && !visited[nx][ny]){

                    if(entrance[0]==nx && entrance[1]==ny){
                        count++;
                        return;
                    }

                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        count++;
    }
    count=-1;
}

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int n=maze.size();
    int m=maze[0].size();
    vector<vector<int>>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0 || j==0 || i==n-1 || j==m-1) && maze[i][j]=='.' &&!(i==entrance[0] && j==entrance[1])){
                temp.push_back({i,j});
            }
        }
    }

    if(temp.empty()) 
    return -1;
    int count=0;
    BFS(maze,entrance,temp,count);
    if(count==0) 
    return -1;
    return count;
}
};