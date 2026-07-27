class Solution {
public:
 void DFS(vector<vector<char>>& board,int i,int j,int m,int n){
    if(i<0||j<0||i>=m||j>=n||board[i][j]!='O')
        return;

    board[i][j]='#';

    DFS(board,i,j-1,m,n);
    DFS(board,i,j+1,m,n);
    DFS(board,i-1,j,m,n);
    DFS(board,i+1,j,m,n);
 }

 void solve(vector<vector<char>>& board) {
    int m=board.size();
    int n=board[0].size();

    for(int i=0;i<m;i++){
        DFS(board,i,0,m,n);
        DFS(board,i,n-1,m,n);
    }

    for(int j=0;j<n;j++){
        DFS(board,0,j,m,n);
        DFS(board,m-1,j,m,n);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O')
                board[i][j]='X';
            else if(board[i][j]=='#')
                board[i][j]='O';
        }
    }
 }
};

