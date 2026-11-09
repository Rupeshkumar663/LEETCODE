//Time Complexity: O(m*n)
//Space Complexity: O(m+n)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>Row(m,0);
        vector<int>Column(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    Row[i]++;
                    Column[j]++;
                }
            }
        }
        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (Row[i]>1 || Column[j]>1)){
                    result++;
                }
            }
        }
        return result;
    }
};
