class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        long long maxi=0;
        unordered_set<int>s;
        int i=0;
        int j=0;
        for(i=0;i<n;i++){
            while(s.count(nums[i])){
                s.erase((nums[j]));
                sum=sum-nums[j];
                j++;
            }
            s.insert(nums[i]);
            sum=sum+nums[i];

            if(i-j+1==k){
                maxi=max(maxi,sum);
                 s.erase(nums[j]);
                sum=sum-nums[j];
                j++;
            }
           
        }
        return maxi;
    }
};