/*class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0;
        int blue=0;
        int white=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
              red++;
             else if(nums[i]==1)
              white++;
              else
              blue++;
         }
        nums.clear();
        for(int i=0;i<red;i++)
           nums.push_back(0);
           for(int i=0;i<white;i++)
           nums.push_back(1);
           for(int i=0;i<blue;i++)
           nums.push_back(2);
    }
};*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0;
        int white=0;
        int blue=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                red++;
            else if(nums[i]==1)
                white++;
            else
                blue++;
        }
        int index=0;
        while(red--)
            nums[index++]=0;
        while(white--)
            nums[index++]=1;
        while(blue--)
            nums[index++]=2;
    }
};