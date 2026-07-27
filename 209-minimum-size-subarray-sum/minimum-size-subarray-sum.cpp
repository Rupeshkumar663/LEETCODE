class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int result=INT_MAX;
        int sum=0;
        int i=0,j=0;

        //Create Window------------------
        while(j<n){
            sum+=nums[j];
            if(sum>=target){
                break;
            }
            j++;
        } 
        if(sum<target){
            return 0;
        }
        result=min(result,j-i+1);
        //Sliding Window-----------------
        while(j<n){
            while(sum>=target){
                result=min(result,j-i+1);
                sum-=nums[i];
                i++;
            }
              j++;
             if(j<n)
            sum+=nums[j];
        }
        return result;
    }
};