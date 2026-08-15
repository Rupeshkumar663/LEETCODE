class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>nums(n);
        nums[n-1]=0;
        int large=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>large){
               nums[i]=0;
               large=prices[i];
            }else{
              nums[i]=large-prices[i];
            }
        }
        return *max_element(nums.begin(),nums.end());
    }
};