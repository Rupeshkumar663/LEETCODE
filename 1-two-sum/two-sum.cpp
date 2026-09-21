/*
Time Complexity: O(n*n)
//Brute Force Approach-------------
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((nums[i]+nums[j])==target){
                    return {i,j};
                }
            }
        }
        return {0,0};
    }
};*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int temp=target-nums[i];
            if(m.find(temp)!=m.end()){
                return {m[temp],i};
            }
            m[nums[i]]=i;
        }
        return {0,0};
    }
};