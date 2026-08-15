/*
//Time Complexity: O(n*n)
//Space COmplexity: O(1)
//Brute force Approach-----------
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int temp=k;
            int count=0;
            for(int j=i;j<n;j++){
                if(nums[j]==0){
                  if(temp==0)
                    break;
                    temp--; 
                }
                count++;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};
*/

//Time Complexity: O(n*n)
//Space COmplexity: O(1)
//Brute force Approach-----------
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int i=0,j=0;
        while(j<n){
          if(nums[j]==0){
              k--;
             while(k<0){
                if(nums[i]==0)
                  k++;
                i++;
             }
          }
         maxi=max(maxi,j-i+1);
         j++;
        }
        return maxi;
    }
};