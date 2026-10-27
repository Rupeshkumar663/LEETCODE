/*class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n)
          return -1.0;
    double sum=0;
        double maxi=0;
        int i;
        for(i=0;i<k;i++){
            sum+=nums[i];
        }
        maxi= sum/k;
        int j=0;
        while(i<n){
            sum+=nums[i];
            sum-=nums[j];
            i++;
            j++;
            maxi=max((sum/k),maxi);
        }
        return maxi;
    }
};*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k){
            return -1.0;
        }
       double maxi=0;
       double sum=0;
       int i=0,j=0;
       for(j=0;j<k;j++){
          sum+=nums[j];
       }
       
        maxi=sum/k;
        while(j<n){
            sum+=nums[j];
            sum-=nums[i];
            maxi=max(maxi,sum/k);
            i++,j++;
        }
        return maxi;
    }
};