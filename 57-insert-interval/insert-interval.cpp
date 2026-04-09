class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>result;
        int start=newInterval[0];
        int end=newInterval[1];
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1]<start){
                result.push_back(intervals[i]);
            } 
            else if(intervals[i][0]>end){
                result.push_back({start,end});
                end=intervals[i][1];
                start=intervals[i][0];
            }else if(intervals[i][1]>=start){
                end=max(end,intervals[i][1]);
                start=min(start,intervals[i][0]);
            } 
        }
         result.push_back({start,end});
        return result;
    }
};