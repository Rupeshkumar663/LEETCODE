//T.C-O(n)
//S.C-O(n)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>nums(gain.size()+1);
        nums[0]=0;
        int prev=0;
        for(int i=0;i<gain.size();i++){
            nums[i+1]=gain[i]+prev;
            prev=gain[i]+prev;
        }
      return *max_element(nums.begin(),nums.end());
    }
};