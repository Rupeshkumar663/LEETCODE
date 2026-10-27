/*class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long result=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    result+=((long long)nums[i]/nums[j])-1;
                }
            }
        }
        return result;
    }
};*/

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long result=0;
        long long prev=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>prev){
                long long parts=(nums[i]+prev-1)/prev;
                result+=parts-1;
                prev=nums[i]/parts;
            }
            else{
                prev=nums[i];
            }
        }
        return result;
    }
};