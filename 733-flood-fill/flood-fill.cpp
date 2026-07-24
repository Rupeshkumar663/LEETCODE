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
  vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
void DFS(vector<vector<int>>& image, int i, int j, int &color,int startingcolor){
   if(i<0 || i>=m || j<0 || j>=n || image[i][j]!=startingcolor){
    return;
   }
   image[i][j]=color;
   for(auto idx:dir){
      DFS(image,i+idx[0],j+idx[1],color,startingcolor);
   }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        if (image[sr][sc] == color)
        return image;
      DFS(image,sr,sc,color,image[sr][sc]);
      return image;
    }
};