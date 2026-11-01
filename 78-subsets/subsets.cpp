class Solution {
public:
int n;
void Solve(int i,vector<int>temp,vector<vector<int>>&result,vector<int>&nums){
    if(i==n){
        return;
    }
    temp.push_back(nums[i]);
    result.push_back(temp);
    Solve(i+1,temp,result,nums);
    temp.pop_back();
    Solve(i+1,temp,result,nums);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>result;
        result.push_back({});
        vector<int>temp;
        Solve(0,temp,result,nums);
        return result;
    }
};