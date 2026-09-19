class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>nums1;
        vector<int>nums2;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==0){
            nums1.push_back(nums[i]);
           }else{
             nums2.push_back(nums[i]);
           }
        }
       nums.clear();
       for(int i=0;i<nums2.size();i++){
        nums.push_back(nums2[i]);
       }
       for(int i=0;i<nums1.size();i++){
        nums.push_back(nums1[i]);
       }
    }
};