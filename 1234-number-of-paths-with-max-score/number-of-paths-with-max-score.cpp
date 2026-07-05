
/*
class Solution {
public:
  int n;
  int maxi=0;
  int maxisum=0;
  int sum=0;
  const int MOD=1e9+7;
   void DFS(vector<string>& board,int i,int j,int sum){
    if(board[i][j]=='X'){
        return;
    }
      if(board[i][j]!='E' && board[i][j]!='X' && board[i][j]!='S'){
        sum+=board[i][j]-'0';
      }
      if(board[i][j]=='E'){
        if(sum>maxisum){
          maxisum=sum;
          maxi=1;
        }
       else if(sum==maxisum){
          maxi=(maxi+1)%MOD;
        }
         return;
      }
      if(i-1>=0 && board[i-1][j]!='X'){
          DFS(board,i-1,j,sum);
      }
      if(j-1>=0 && board[i][j-1]!='X'){
          DFS(board,i,j-1,sum);
      }
      if(i-1>=0 && j-1>=0 && board[i-1][j]=='X' && board[i][j-1]=='X' && board[i-1][j-1]!='X'){
        DFS(board,i-1,j-1,sum);
      }
   }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
       DFS(board,n-1,n-1,0);
       return {maxisum,maxi};
    }
};
*/
//Time Complexity: O(n^2)
//Space Complexity: O(n^2)
class Solution {
public:
    const int MOD=1e9+7;
    int n;
    int dp[101][101];
    int way[101][101];
    bool visited[101][101];
    int DFS(vector<string>&board,int i,int j){
        if(i<0||j<0||board[i][j]=='X')
            return -1;
        if(i==0&&j==0){
            way[0][0]=1;
            return 0;
        }
        if(visited[i][j])
            return dp[i][j];
        visited[i][j]=true;
        int up=DFS(board,i-1,j);
        int left=DFS(board,i,j-1);
        int diag=DFS(board,i-1,j-1);
        int maxisum=max({up,left,diag});
        if(maxisum==-1){
            dp[i][j]=-1;
            way[i][j]=0;
            return dp[i][j];
        }
        long long count=0;
        if(up==maxisum)
            count=(count+way[i-1][j])%MOD;
        if(left==maxisum)
            count=(count+way[i][j-1])%MOD;
        if(diag==maxisum)
            count=(count+way[i-1][j-1])%MOD;
        int val=0;
        if(board[i][j]!='S')
            val=board[i][j]-'0';
        dp[i][j]=maxisum+val;
        way[i][j]=count%MOD;
        return dp[i][j];
    }
    vector<int> pathsWithMaxScore(vector<string>&board){
        n=board.size();
        memset(visited,0,sizeof(visited));
        memset(dp,-1,sizeof(dp));
        memset(way,0,sizeof(way));
        int score=DFS(board,n-1,n-1);
        if(score==-1)
            return {0,0};
        return {score,way[n-1][n-1]};
    }
};