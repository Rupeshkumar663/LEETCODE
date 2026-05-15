//T.C-O(2^n)
//Recursion Approach
/*
class Solution {
public:
    int n;
    int solve(int idx, int prev, vector<int>& nums){
        if (idx==nums.size()){
            return 0;
        }
        int skip=solve(idx+1,prev,nums);
        int take=0;
        if(prev==-1 || nums[idx]>nums[prev]){
            take=1+solve(idx+1,idx,nums);
        }
        return max(take,skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        return solve(0,-1,nums);
    }
};
*/

class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(int idx, int prev, vector<int>& nums){
        if (idx==nums.size()){
            return 0;
        }
        
         if(dp[idx][prev+1]!=-1 ){
            return dp[idx][prev+1];
        }
       
        int skip=solve(idx+1,prev,nums);
        int take=0;
        if(prev==-1 || nums[idx]>nums[prev]){
            take=1+solve(idx+1,idx,nums);
        }
        return dp[idx][prev+1]=max(take,skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
    }
};

