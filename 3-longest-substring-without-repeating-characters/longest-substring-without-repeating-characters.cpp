/*//Time Complexity:O(n)*O(k)=O(n)
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
};*/


//Time Complexity: O(n)
//Space Complexity: O(n)
//Sliding Window Approach-------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
      unordered_map<char,int>m;
      int i=0,j=0;
      int count=0;
      while(j<n){
          if(m.find(s[j])!=m.end()){
            if(m[s[j]]>=i){
               i=m[s[j]]+1;
               m[s[j]]=j;
             }
          }
          m[s[j]]=j;
          count=max(count,j-i+1);
          j++;
      }
      return count;
    }
};