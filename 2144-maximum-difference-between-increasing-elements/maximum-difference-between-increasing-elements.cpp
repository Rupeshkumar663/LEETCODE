/*class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            if(nums[i]<nums[j])
              maxi=max(maxi,nums[j]-nums[i]);
          }
        }
        if(maxi==INT_MIN)
         return -1;
       return maxi;
    }
};

*/


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int temp=nums[0];
        for(int i=1;i<n;i++){
          if(temp<nums[i]){
            maxi=max(maxi,nums[i]-temp);
          }else{
            temp=nums[i];
          }
        }
        if(maxi==INT_MIN)
         return -1;
       return maxi;
    }
};

