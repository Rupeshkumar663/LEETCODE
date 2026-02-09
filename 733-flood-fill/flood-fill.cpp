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
};