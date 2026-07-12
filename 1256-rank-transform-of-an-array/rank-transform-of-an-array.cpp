class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>nums=arr;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>rank;
        int r=1;
        for(int E:nums){
            if(rank.find(E)==rank.end()){
                rank[E]=r++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=rank[arr[i]];
        }
        return arr;
    }
};