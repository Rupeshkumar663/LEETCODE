class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char>ss;
       int result=0;
       int i=0;
       for(int j=0;j<s.length();j++){
        while(ss.count(s[j])){
            ss.erase(s[i]);
            i++;
        }
          ss.insert(s[j]);
          result=max(result,j-i+1);
       }
       return result;
    }
};