//Time Complexity: O(nlogn)
//Space Complexity: O(1)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int coverInterval=0;
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){//Sorting intervals if starting are equal then short on the basis of finish
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });//O(nlogn)
         int count=0;
         int maxi_end=0;//store max end
        for(int i=0;i<n;i++){//O(n)
           if(maxi_end<intervals[i][1]){
            count++;
            maxi_end=intervals[i][1];
           }
        }
        return count;
    }
};