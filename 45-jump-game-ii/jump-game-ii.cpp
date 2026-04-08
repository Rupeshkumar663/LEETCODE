class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi=0;
        int count=0;
        int current=0;
        for(int i=0;i<nums.size()-1;i++){
            maxi=max(maxi,i+nums[i]);
            if(i==current){
                count++;
                current=maxi;
            }
        }
     return count;
    }
};