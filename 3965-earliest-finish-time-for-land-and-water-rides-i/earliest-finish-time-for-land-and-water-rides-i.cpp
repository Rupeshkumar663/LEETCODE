class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
      int n=landStartTime.size();
      int m=waterStartTime.size();
      vector<vector<int>>land;
      vector<vector<int>>water;
      for(int i=0;i<n;i++){
        land.push_back({landStartTime[i],landDuration[i]});
      }
      for(int i=0;i<m;i++){
        water.push_back({waterStartTime[i],waterDuration[i]});
      } 
      int result=INT_MAX;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           int temp1 = max(land[i][0] + land[i][1], water[j][0]) + water[j][1];
           int temp2 = max(water[j][0] + water[j][1], land[i][0]) + land[i][1];
           result=min(result,min(temp1,temp2));
        }
       }
      return result;
    }
};