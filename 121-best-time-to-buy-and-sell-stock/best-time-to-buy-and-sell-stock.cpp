/*//Time Complexity: O(n)
//Space Complexity: O(n)
//Bottom-Up Approach--------------
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
};*/

/*
//Time Complexity: O(n*n)
//Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      int profit=0;
      for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            profit=max(profit,prices[j]-prices[i]);
        }
      } 
      return profit;
    }
};*/


//Time Complexity: O(n*n)
//Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      int profit=0;
      int prev=prices[n-1];
      for(int i=n-2;i>=0;i--){
            profit=max(profit,prev-prices[i]);
            if(prices[i]>prev)
              prev=prices[i];
      } 
      return profit;
    }
};