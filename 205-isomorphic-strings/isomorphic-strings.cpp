class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m1,m2;
        for(int i=0;i<s.length();i++){
           if(m1.count(s[i]) && m1[s[i]]!=t[i])
              return false;
            if(m2.count(t[i]) && m2[t[i]]!=s[i])
              return false;
             m1[s[i]]=t[i];
             m2[t[i]]=s[i];
        }
        return true;
    }
};