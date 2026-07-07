//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;//Cancatenate non-Zero digits
        long long sum=0;//sum of all non-Zero digits
        while(n){//Time Complexity: O(n)
          if(n%10!=0){
           x=x*10+n%10;//X store Cancatenates in reverse order
           sum+=n%10;
          }
          n=n/10;
        }
        long long result=0;//result store Cancatenates in actual order
        while(x){//Time Complexity: O(n)
          if(x%10!=0){
           result=result*10+x%10;
          }
          x=x/10;  
        }
        return result*sum;//multiplication of sum of non-zero and cancatenates of non-zero
    }
};