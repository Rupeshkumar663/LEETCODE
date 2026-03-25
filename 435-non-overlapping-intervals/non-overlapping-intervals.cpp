class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });
        int n=intervals.size();
        int count=1;
        int start=intervals[0][0];
        int finish=intervals[0][1];
        for(int i=1;i<n;i++){
           if(finish<=intervals[i][0]){
             start=intervals[i][0];
             finish=intervals[i][1];
             count++;
           }
        }
      return n-count;
    }
};