class Solution {
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
};