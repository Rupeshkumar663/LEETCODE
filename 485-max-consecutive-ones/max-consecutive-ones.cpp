class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int prev=-1;
        int max_count=0;

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(prev==-1 || nums[prev]==1){
                    count++;
                }else{
                    count=1;
                }
                prev=i;
            }else{
                max_count=max(max_count,count);
                count=0;
                prev=i;
            }
        }

        max_count=max(max_count,count);
        return max_count;
    }
};