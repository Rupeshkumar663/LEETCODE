class Solution {
public:
   bool isSubsetSum(vector<int>& nums, int sum) {
       int n=nums.size();
       vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
       dp[0][0]=true;
       for(int i=1;i<n+1;i++){
           dp[i][0]=true;
       }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                bool take=false;
                if(j>=nums[i-1]){
                  take=dp[i-1][j-nums[i-1]];
                 }
                 bool skip=dp[i-1][j];
                 dp[i][j]=skip || take;
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
       return isSubsetSum(nums,sum/2);
    }
};