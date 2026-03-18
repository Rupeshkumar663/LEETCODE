class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int temp=n/3;
      vector<int>result;
       for(auto x:m){
        if(x.second>temp){
            result.push_back(x.first);
        }
       }
     return result;
    }
};