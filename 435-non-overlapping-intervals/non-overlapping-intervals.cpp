/*class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        int n=intervals.size();
        int count=1;
        int finish=intervals[0][1];
        for(int i=1;i<n;i++){
           if(finish<=intervals[i][0]){
             finish=intervals[i][1];
             count++;
           }
        }
      return n-count;
    }
};*/

//Time Complexity: O(nlogn)+O(n)=O(nlogn)
//Space Complexity: O(n)
//Greedy Approach--------------- 
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });//sort Intervals on the basis of end. Time Complexyt: O(nlogn)
        int start=intervals[0][0];
        int end=intervals[0][1];
        int count=1;
        for(int i=1;i<intervals.size();i++){//Time COmplexity: O(n)
           if(end<=intervals[i][0]){//if condition satisfied then count increasee y one.
            count++;
            end=intervals[i][1];
           }
        }
        return intervals.size()-count;
    }
};