//Time Complexity:O(n)*O(k)=O(n)
//Space Complexity: O(n)
//Sliding Window Approach-------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char>ss;
       int result=0;
       int i=0;
       for(int j=0;j<s.length();j++){//Time Complexity: O(n)
        while(ss.count(s[j])){//Time Complexity: O(k)
            ss.erase(s[i]);
            i++;
        }
          ss.insert(s[j]);
          result=max(result,j-i+1);
       }
       return result;
    }
};