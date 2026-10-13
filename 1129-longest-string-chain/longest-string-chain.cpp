/*//Time COmplexity: O(2^n*l)
//Space Complexity: O(1)
class Solution {
public:
  bool checkvalid(string a,string b){
    if((a.size()+1)!=b.size()){
       return false;
    }
    int i=0,j=0;
     while(i<a.size() && j<b.size()){
        if(a[i]==b[j]){
            i++;
            j++;
        }else{
            j++;
        }
     }
     return i==a.size();
  }
  
  int Solve(int i,int prev,vector<string>&words){
    if(i==words.size()){
        return 0;
    }
    
    int take=0;
    if(prev==-1 || checkvalid(words[prev],words[i])){
      take=1+Solve(i+1,i,words);
    }
    int skip=Solve(i+1,prev,words);
    return max(skip,take);
  }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
          return a.size()<b.size();
        });
        return Solve(0,-1,words);
    }
};


//Time Complexity: O(n*n*l)
//Space Complexity: O(n*n)
class Solution {
public:
  bool checkvalid(string a,string b){
    if((a.size()+1)!=b.size()){
       return false;
    }
    int i=0,j=0;
     while(i<a.size() && j<b.size()){
        if(a[i]==b[j]){
            i++;
            j++;
        }else{
            j++;
        }
     }
     return i==a.size();
  }
   int dp[1001][1001];
  int Solve(int i,int prev,vector<string>&words){
    if(i==words.size()){
        return 0;
    }
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }
    int take=0;
    if(prev==-1 || checkvalid(words[prev],words[i])){
      take=1+Solve(i+1,i,words);
    }
    int skip=Solve(i+1,prev,words);
    return dp[i][prev+1]=max(skip,take);
  }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
          return a.size()<b.size();
        });
        memset(dp,-1,sizeof(dp));
        return Solve(0,-1,words);
    }
};
*/

//Time Complexity: O(n*n*l)
//Space Complexity: O(n*n)
class Solution {
public:
    bool checkvalid(string &a,string &b){
        if(a.size()+1!=b.size())
           return false;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i==a.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),
             [](string &a,string &b){
                 return a.size()<b.size();
             });
        int n=words.size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(checkvalid(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
