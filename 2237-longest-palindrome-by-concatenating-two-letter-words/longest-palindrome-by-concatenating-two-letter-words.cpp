class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       unordered_map<string,int>m;
       for(int i=0;i<words.size();i++)
          m[words[i]]++;
        int count=0;
        bool center=false;
        for(auto &v:m){
           string s=v.first;
           string r=s;
           reverse(r.begin(),r.end());
           if(s==r){
             if(v.second%2)
                center=true;
            count+=(v.second/2)*4;
           } 
          else if(s<r && m.count(r)){
               int temp=min(m[r],m[s]);
               count+=temp*4;
          }
        }
        if(center)
          count+=2;
      return count;
    }
};