/*//Time COmplexity: O(n)
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
};*/

//Time COmplexity: O(n)
//space Complexity: O(k)
//Sliding Window Approach------------------
/*class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n){
                if(nums[i]==nums[j] && abs(i-j)<=k)
                   return true;
                j++;
            }
            i++;
        }
        return false;
    }
};*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end()){
               if(abs(m[nums[i]]-i)<=k)
                  return true;
            }
            m[nums[i]]=i;
        }
        return false;
    }
};