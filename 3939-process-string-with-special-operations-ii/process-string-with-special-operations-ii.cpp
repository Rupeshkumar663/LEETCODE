/*
T.C-O(2^n)->in Worst case
S.C-O(2^n)->in Worst case
class Solution {
public:

    char processStr(string s, long long k) {
        int n=s.length();
        string result="";
        for(int i=0;i<n;i++){
           if(s[i]=='#'){
               result+=result;
           } else if(s[i]=='*'){
              if(!result.empty())
               result.pop_back();
           } else if(s[i]=='%'){
            reverse(result.begin(),result.end());
           }else{
              result.push_back(s[i]);
           }
        }
        if(k>=result.size()){
            return '.';
          }
        return result[k];
    }
};
*/
class Solution {
public:

    char processStr(string s, long long k) {
        int n=s.length();
        long long l=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(l>0){
                    l--;
                }
            } else if(s[i]=='%'){
                continue;
            } else if(s[i]=='#'){
                l*=2;
            } else{
                l++;
            }
        }
        if(l<=k || k<0){
            return '.';
        }
     for(int i=n-1;i>=0;i--){
      if(s[i]=='#'){
        long long half=l/2;
         if(k>=half)
            k-=half;
          l=half;
        }
      else if(s[i]=='%'){
         k=l-k-1;
      }
    else if(s[i]=='*'){
        l++;
        if(k==l-1){
        }
    }
    else{
        l--;
        if(k==l)
            return s[i];
        }
     }
     return  '.';
   }
};