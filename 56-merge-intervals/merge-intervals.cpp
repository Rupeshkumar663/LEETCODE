//Time complexity: O(nlogn)+O(n)=O(nlogn)
//Space complexity: O(n)
//Greedy Approach--------------
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());//Time complexity: O(nlogn)
        int start=intervals[0][0];
        int end=intervals[0][1];
        vector<vector<int>>result;//Space complexity: O(n)
        for(int i=1;i<intervals.size();i++){//Time complexity: O(n)
            if(end>=intervals[i][0]){
                end=max(end,intervals[i][1]);
            }else{
                result.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
         result.push_back({start,end});
         return result;
    }
};