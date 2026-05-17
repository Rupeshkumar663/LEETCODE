//Recursion--
/*
class Solution {
public:
  int n;
  long long solve(int i,int j,vector<int>&nums){
    if(i>=n){
        return 0;
    }
    long long skip=solve(i+1,j,nums);
    long long take=0;
    if(j==-1 || nums[i]-i>=nums[j]-j){
      take=nums[i]+solve(i+1,i,nums);
    }
    return max<long long>(skip,take);
  }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        n=nums.size();
        long long temp=*max_element(nums.begin(),nums.end());
        if(temp<=0){
            return temp;
        }
       return solve(0,-1,nums);
    };
};
*/

//Test_case-upto 341
//Recursion+memoization

/*
class Solution {
public:
  int n;
  unordered_map<string,long long>dp;
  long long solve(int i,int j,vector<int>&nums){
    if(i>=n){
        return 0;
    }
   string key=to_string(j)+"_"+to_string(i);
   if(dp.find(key)!=dp.end()){
    return dp[key];
   }
    long long skip=solve(i+1,j,nums);
    long long take=0;
    if(j==-1 || nums[i]-i>=nums[j]-j){
      take=nums[i]+solve(i+1,i,nums);
    }
     return dp[key]=max<long long>(skip,take);
  }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        n=nums.size();
        long long temp=*max_element(nums.begin(),nums.end());
        if(temp<=0){
            return temp;
        }
       return solve(0,-1,nums);
    };
};
*/
//T.c-O(n^2)
//Buttom-up
/*
class Solution {
public:
  
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();
        long long temp=*max_element(nums.begin(),nums.end());
        if(temp<=0){
            return temp;
        }
        vector<long long>dp(n);
        for(int i=0;i<n;i++){
            dp[i]=nums[i];
        }
        long long result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
               if(nums[i]-i>=nums[j]-j){
                dp[i]=max<long long>(dp[i],nums[i]+dp[j]);
               }
            }
            result=max(result,dp[i]);
        }
      return result;
    };
};
*/
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        long long temp=*max_element(nums.begin(),nums.end());
        if(temp<=0) 
        return temp;
        map<long long,long long>mp;
        long long result=0;
        for(int i=0;i<nums.size();i++){
            long long key=1LL*nums[i]-i;
            long long best=0;
            auto it=mp.upper_bound(key);
            if(it !=mp.begin()){
                --it;
                best=it->second;
            }
           long long curr=max(1LL*nums[i],best+nums[i]);
            result=max(result,curr);
            if(mp.count(key) && mp[key]>=curr)
                continue;
            mp[key]=curr;
            auto nxt=mp.upper_bound(key);
            while(nxt != mp.end() && nxt->second<=curr){
                auto temp=nxt;
                nxt++;
                mp.erase(temp);
            }
        }
        return result;
    }
};

