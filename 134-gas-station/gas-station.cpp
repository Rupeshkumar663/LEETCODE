/*//Time Complexity: O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<vector<int>>Gas;
        for(int i=0;i<gas.size();i++){
            Gas.push_back({gas[i],cost[i]});
        }
        int start=0;
        int tank=0;
        int total=0;
        for(int i=0;i<Gas.size();i++){
            int diff=Gas[i][0]-Gas[i][1];
            tank +=diff;
            total +=diff;
            if(tank<0){
                start=i+1;
                tank=0;
            }
        }
        if(total<0)
            return -1;
        return start;
    }
};*/

/*//Time Compelxity: O(n*n)
//Space Complexity: O(1)
//Brute Force Approach-----------
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas,vector<int>&cost) {
        int n=gas.size();
        int start=0;
        int sum=0;
        while(start<n){
            sum=0;
            int i=start;
            while(true){
                  sum=sum-cost[i]+gas[i];
                  if(sum<0){
                    break;
                  }
                  i=(i+1)%n;
                 if(i==start){
                    return start;
                 }
            }
            start++;
        }
        return -1;
    }
};*/

//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int tank=0;
        int sum=0;
        for(int i=0;i<gas.size();i++){
            int d=gas[i]-cost[i];
            tank+=d;
            sum+=d;
            if(tank<0){
                tank=0;
                start=i+1;;
            }
        }
        if(sum<0){
            return -1;
        }
        return start;
    }
};