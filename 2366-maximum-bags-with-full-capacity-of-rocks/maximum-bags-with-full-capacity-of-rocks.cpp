//Time Complexity: O(nlogn)
//Solve By Greedy Approach
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int>need;
        for(int i=0;i<n;i++){
            need.push_back(capacity[i]-rocks[i]);
        }
        sort(need.begin(),need.end());
        for(int i=0;i<n;i++){
         if(additionalRocks>=need[i]){
            additionalRocks-=need[i];
            need[i]=0;
          }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(need[i]==0)
              count++;
        }
       return count;
    }
};