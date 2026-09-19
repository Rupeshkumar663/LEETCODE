class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>num;
        num.push_back(nums[0]);
        int prev=nums[0];
       for(int i=1;i<nums.size();i++){
         if(prev!=nums[i]){
             num.push_back(nums[i]);
             prev=nums[i];
         }
       } 
       nums.clear();
       nums=num;
       return num.size();
    }
};