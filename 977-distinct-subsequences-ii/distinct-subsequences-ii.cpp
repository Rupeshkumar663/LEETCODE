/*class Solution {
public:
  int n;
  long long MOD=1e9+7;
   void Solve(int i,string temp,unordered_set<string>&ss,string &s){
      if(i==n){
         ss.insert(temp);
        return;
      }
      temp.push_back(s[i]);
      Solve(i+1,temp,ss,s);
      temp.pop_back();
      Solve(i+1,temp,ss,s);
      
   }
    int distinctSubseqII(string s) {
        n=s.size();
        unordered_set<string>ss;
        Solve(0,"",ss,s);
        long long N=1LL*(ss.size()-1);
       return N%MOD;
    }
};

class Solution {
public:
  int n;
  long long MOD=1e9+7;
  unordered_set<string>ss;
   int Solve(int i,string temp,string &s){
      if(i==n){
        if(ss.count(temp)){
            return 0;
        }
        ss.insert(temp);
        return 1;

      }
      int take=0;
      if(i<n){
        temp.push_back(s[i]);
         take=Solve(i+1,temp,s);
      }
      temp.pop_back();
      int skip=Solve(i+1,temp,s);
      return take+skip;
   }
    int distinctSubseqII(string s) {
        n=s.size();
        ss.clear();
        return (Solve(0,"",s)-1);
       
    }
};
*/


class Solution {
public:
    const long long MOD=1e9+7;

    long long Solve(int i,string &s,vector<long long>&last,long long dp) {
        if(i==s.size()) return dp;

        int idx=s[i]-'a';

        long long newDp=(2*dp-last[idx]+MOD)%MOD;

        last[idx]=dp;

        return Solve(i+1,s,last,newDp);
    }

    int distinctSubseqII(string s) {
        vector<long long>last(26,0);

        return (Solve(0,s,last,1)-1+MOD)%MOD;
    }
};
