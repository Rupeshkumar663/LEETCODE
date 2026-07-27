class Solution {
public:
int MOD=1337;
    int  modpower(int a,int b){
       int result=1;
       while(b>0){
        if(b%2==1){
            result=result*a%MOD;
        }
        a=((a%MOD)*(a%MOD))%MOD;
        b=b/2;
       }
       return result;
    }
    int superPow(int a,vector<int>& b){
    int result=1;
      a%=MOD;
    for(int digit:b){
        result=modpower(result,10);
        result=(result*modpower(a,digit))%MOD;
    }
    return result;
}
};