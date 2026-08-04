//Time Complexity: O(n*n)
//Space COmplexity: O(1)
//Brute Force Approach----------
/*class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            long long sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if((1LL*nums[j]*(j-i+1)-sum)<=k)
                    maxi=max(maxi,j-i+1);
                else
                    break;
            }
        }
        return maxi;
    }
};*/


//Time Complexity: O(n*logn)
//Space COmplexity: O(1)
//Sliding Window Approach----------
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        long long sum=0;
        int i=0;
        for(int j=0;j<nums.size();j++){
                sum+=nums[j];
                if((1LL*nums[j]*(j-i+1)-sum)<=k)
                    maxi=max(maxi,j-i+1);
                while((1LL*nums[j]*(j-i+1)-sum)>k){
                    sum-=nums[i];
                    i++;
                }
           }
        return maxi;
    }
};