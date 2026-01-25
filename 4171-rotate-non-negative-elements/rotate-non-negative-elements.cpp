class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                temp.push_back(nums[i]);
            }
        }
        if(temp.size()==0)
            return nums;

        k=k%temp.size();
        vector<int>arr1,arr2;
        for(int p=k;p<temp.size();p++){
            arr2.push_back(temp[p]);
        }
        for(int p=0;p<k;p++){
            arr1.push_back(temp[p]);
        }
        temp.clear();
        for(int p=0;p<arr2.size();p++){
            temp.push_back(arr2[p]);
        }
        for(int p=0;p<arr1.size();p++){
            temp.push_back(arr1[p]);
        }
        int m=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                nums[i]=temp[m++];
            }
        }
        return nums;
    }
};
