class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0;
        int r=n-1;
        int sum=0;
        int maxi=0;
        for(int j=0;j<k;j++){
            sum+=cardPoints[j];
        }
        if(k==n)
          return sum;
        maxi=sum;
        while(l<k){
            sum=sum-cardPoints[k-(1+l)];
            sum=sum+cardPoints[r];
           r--;
            l++;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};