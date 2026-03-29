class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<vector<int>>nums;
        for(int i=0;i<n;i++){
            nums.push_back({growTime[i],plantTime[i]});
        }
        sort(nums.begin(),nums.end(),[](vector<int>&a,vector<int>&b){
            return a[0]>b[0];
        });
     
     int result=0;
     int maxiTime=0;
      for(auto & x:nums){
        maxiTime +=x[1];
        result=max(result,maxiTime+x[0]);
      }
     return result;
    }
};