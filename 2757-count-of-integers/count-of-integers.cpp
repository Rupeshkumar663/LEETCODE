class Solution {
public:
int MOD=1e9+7;
int dp[23][2][401];
  long long f(int index,bool tight,int sum,int & min_sum,int & max_sum,string s){
    if(index==s.size()){
        return sum>=min_sum && sum<=max_sum;
    }
    if(dp[index][tight][sum]!=-1){
        return dp[index][tight][sum];
    }
    long long ans=0;
    int limit=tight?s[index]-'0':9;
    for(int d=0;d<=limit;d++){
        bool newTight=tight && (d==limit);
       ans = (ans + f(index + 1, newTight, sum + d,
               min_sum, max_sum, s)) % MOD;
    }
    return dp[index][tight][sum]=ans;
  }
    int count(string num1, string num2, int min_sum, int max_sum) {
      
      memset(dp,-1,sizeof(dp));
      long long countNums1=f(0,true,0,min_sum,max_sum,num1);
      memset(dp,-1,sizeof(dp));
      int sum=0;
      for(int i=0;i<num1.size();i++){
        sum+=num1[i]-'0';
      }
      if(sum>=min_sum && sum<=max_sum){
        countNums1--;
      }
      long long countNums2=f(0,true,0,min_sum,max_sum,num2);
      return (((countNums2-countNums1)%MOD)+MOD)%MOD;
    }
};