//T.C-O(2^n)
//S.C-O(n)
//Recursion
//Test Case-Run upto 47
/*
class Solution {
public:
  int n;
    vector<int>result;
    vector<int>temp;
    void solve(int idx,int prev,vector<int>&nums){
        if(idx>=n){
           if(result.size()<temp.size()){
                result=temp;
            }
            return ;
        }
        solve(idx+1,prev,nums);
        if(prev==-1 || (nums[idx]%nums[prev]==0 || nums[prev]%nums[idx]==0)){
            temp.push_back(nums[idx]);
            solve(idx+1,idx,nums);
            temp.pop_back();
        }
     return ;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        solve(0,-1,nums);
        return result;
    }
};

*/
class Solution {
public:

    int n;
    vector<int> nums;
    
    // dp[idx][prev+1] => maximum length
    int dp[1001][1001];

    int solve(int idx,int prev){

        // base case
        if(idx >= n){
            return 0;
        }

        // memoization
        if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
        }

        // skip
        int notTake = solve(idx+1, prev);

        // take
        int take = 0;

        if(prev == -1 || nums[idx] % nums[prev] == 0){

            take = 1 + solve(idx+1, idx);
        }

        return dp[idx][prev+1] = max(take, notTake);
    }

    vector<int> largestDivisibleSubset(vector<int>& arr) {

        nums = arr;

        sort(nums.begin(), nums.end());

        n = nums.size();

        memset(dp, -1, sizeof(dp));

        solve(0,-1);

        // subset build karna
        vector<int> ans;

        int idx = 0;
        int prev = -1;

        while(idx < n){

            int take = 0;

            if(prev == -1 || nums[idx] % nums[prev] == 0){

                take = 1 + solve(idx+1, idx);
            }

            int notTake = solve(idx+1, prev);

            // agar take better hai to include karo
            if(take >= notTake &&
               (prev == -1 || nums[idx] % nums[prev] == 0)){

                ans.push_back(nums[idx]);

                prev = idx;
            }

            idx++;
        }

        return ans;
    }
};