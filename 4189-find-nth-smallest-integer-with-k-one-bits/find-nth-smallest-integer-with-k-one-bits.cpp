class Solution {
public:
    long long temp[55][55];
    long long nthSmallest(long long n, int k) {

        for(int i=0;i<=50;i++){
            temp[i][0]=temp[i][i]=1;
            for(int j=1;j<i;j++){
                temp[i][j]=min((long long)4e18,temp[i-1][j-1]+temp[i-1][j]);
            }
        }

        long long result = 0;
        for(int i=49;i>=0;i--){
            if(k==0)
                break;
            long long count=temp[i][k];
            if(count<n){
                n-=count;
               result|=(1LL<<i);
                k--;
            }
        }
        return result;
    }
};
