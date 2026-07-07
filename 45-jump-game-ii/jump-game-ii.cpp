//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
     int n=nums.size();
     int maxi=0;//Store maximum jump can I do.
     int count=0;//count minimum number of jump 
     int current=0;//store current index after jump
     for(int i=0;i<n-1;i++){//Time Complexity: O(n)
        maxi=max(maxi,i+nums[i]);
        if(i==current){//if condition satisfied then will jump and count increase by 1.
            count++;
            current=maxi;
        }
      }
    return count;//return minimum number of jump to reach last index.
   }
};