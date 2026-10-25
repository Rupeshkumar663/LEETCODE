/*//Time Complexity: O(n)
//Space Complexity: O(1)
//optimal Solution by Sliding Window-----------------
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int result=INT_MAX;
        int sum=0;
        int i=0,j=0;

        //Create Window------------------
        while(j<n){//Time Complexity: O(n)
            sum+=nums[j];
            if(sum>=target){
                break;
            }
            j++;
        } 
        if(sum<target){
            return 0;
        }
        result=min(result,j-i+1);
        //Sliding Window-----------------
        while(j<n){//Time Complexity: O(n)
            while(sum>=target){
                result=min(result,j-i+1);
                sum-=nums[i];
                i++;
            }
              j++;
             if(j<n)
            sum+=nums[j];
        }
        return result;
    }
};*/

/*//Time Complexity: O(n)
//Space Complexity: O(1)
//optimal Solution by Sliding Window-----------------
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int result=INT_MAX;
        int i=0,j=0;
        int sum=0;
        while(j<n){
            sum=sum+nums[j];
            if(sum>=target)
               break;
            j++;
        }
        if(sum<target){
            return 0;
        }
         result=min(result,j-i+1);
       while(j<n){//Time Complexity: O(n)
            while(sum>=target){
                result=min(result,j-i+1);
                sum-=nums[i];
                i++;
            }
              j++;
             if(j<n)
            sum+=nums[j];
        }
        return result;
    }
};*/

//Time Complexity: O(n)
//Space Complexity: O(1)
//optimal Solution by Sliding Window-----------------
class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int sum=0;
        int i=0,j=0;
        for(j=0;j<n;j++){
            sum+=nums[j];
            if(sum>=target)
              break;
        }
        if(sum<target){
            return 0;
        }
        mini=min(mini,j-i+1);
        while(j<n){
            while(sum>=target){
                mini=min(mini,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
            if(j<n)
            sum+=nums[j];
            
        }
        return mini;
    }
};