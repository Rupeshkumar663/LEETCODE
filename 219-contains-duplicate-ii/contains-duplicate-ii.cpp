//Time COmplexity: O(n)
//space Complexity: O(k)
//Sliding Window Approach------------------
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>s;//space Complexity: O(k)
        for(int i=0;i<nums.size();i++){//Time COmplexity: O(n)
          if(s.count(nums[i]))
            return true;
          s.insert(nums[i]);
          if(s.size()>k){
            s.erase(nums[i-k]);
          }
        }
        return false;
    }
};