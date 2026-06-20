//T.C-O(n*logn)
//Greedy+sorting
class Solution {
public:
    int maxBuilding(int n,vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});
        sort(restrictions.begin(),restrictions.end());
        for(int i=1;i<restrictions.size();i++){
            int dist=restrictions[i][0]-restrictions[i-1][0];
            restrictions[i][1]=min(restrictions[i][1],restrictions[i-1][1]+dist);
        }
        for(int i=restrictions.size()-2;i>=0;i--){
            int dist=restrictions[i+1][0]-restrictions[i][0];
            restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+dist);
        }
        int result=0;
        for (int i=1;i<restrictions.size();i++){
            int x1=restrictions[i-1][0];
            int h1=restrictions[i-1][1];
            int x2=restrictions[i][0];
            int h2=restrictions[i][1];
            int dist=x2-x1;
            int peak=(h1+h2+dist)/2;
            result=max(result,peak);
        }
        return result;
    }
};