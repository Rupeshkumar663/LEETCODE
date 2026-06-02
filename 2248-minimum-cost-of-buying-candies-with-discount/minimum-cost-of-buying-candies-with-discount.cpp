class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),[](int &a,int &b){
            return a>b;
        });
       int result=0;
        for(int i=0;i<cost.size();i++){
            if((i+1)%3!=0){
                result+=cost[i];
            }
        }

        return result;
    }
};