class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=n-1,j=n-2;i>0,j>=0;i--,j--){
            if(nums[i]<=nums[j])
                 return i;
        }
        return 0;
    }
};