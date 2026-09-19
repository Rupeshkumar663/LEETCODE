class Solution {
public:
    void rotate(vector<int>& nums,int k) {
        vector<int>nums1;
        vector<int>nums2;
        k=k%nums.size();
        for(int i=nums.size()-k;i<nums.size();i++){
           nums1.push_back(nums[i]); 
        }
        for(int i=0;i<(nums.size()-k);i++){
           nums2.push_back(nums[i]);
        }
        nums.clear();
        for(int i=0;i<nums1.size();i++){
            nums.push_back(nums1[i]);
        }
         for(int i=0;i<nums2.size();i++){
            nums.push_back(nums2[i]);
        }
    }
};