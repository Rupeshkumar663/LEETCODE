/*
//APPROACH-1 BY DFS----------------------------------------
class Solution {
public:
void DFS(vector<vector<int>>& image, int i, int j,int&n,int &m ,int color,int startingcolor){
  if(i<0 || j<0 || i>=m || j>=n || image[i][j]!=startingcolor){
    return;
  }
   image[i][j]=color;
    DFS(image,i,j-1,n,m,color,startingcolor);//left
    DFS(image,i,j+1,n,m,color,startingcolor);//right
    DFS(image,i-1,j,n,m,color,startingcolor);//up
    DFS(image,i+1,j,n,m,color,startingcolor);//down
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        if(image[sr][sc]==color){
            return image;
        } else{
            DFS(image,sr,sc,n,m,color,image[sr][sc]);
        }
    return image;
    }
};*/
//APPROACH-2 BY BFS------------------------------------------
class Solution {
public:
   int m,n;
  void BFS(vector<vector<int>>& image, int sr, int sc, int color,int startingcolor){
    queue<vector<int>>q;
    q.push({sr,sc});
    image[sr][sc]=color;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    while(!q.empty()){
        vector<int>temp=q.front();
        q.pop();
        int x=temp[0];
        int y=temp[1];

        for(int d=0;d<4;d++){
                int nx=x+dx[d];
                int ny=y+dy[d];
                if(nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny]==startingcolor){
                    image[nx][ny]=color;
                    q.push({nx,ny});
                }
        }
    }
  }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        if(image[sr][sc]==color){
            return image;
        } else{
            BFS(image,sr,sc,color,image[sr][sc]);
        }
    return image;
    }
};