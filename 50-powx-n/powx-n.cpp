
//Time Complexity :O(n)
//Space Complexity :O(1)
/*class Solution {
public:
  double modpower(double x,long long n){
    double result=1.0;
    while(n){
        if(n%2==1){
            result=(double)result*x;
        }
       n=n/2;
       x=x*x;
    }
    return result;
  }
    double myPow(double x, int n) {
        if(n<0){
            long long t=(-1LL)*n;
            double result=modpower(x,t);
            return 1/result;
        }
        return modpower(x,n);
    }
};*/

class Solution {
public:
 
    double myPow(double x, long long n) {
        if(n==0){
            return 1;
        }
        if(n<0){
         return 1/myPow(x,-n);
        }
       if(n%2==0)
        return myPow(x*x,n/2);
        return x*myPow(x*x,(n-1)/2);
    }
};