/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i=0;
        int sum=0;
        int count=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>k && i<=j){
                sum-=nums[i];
                i++;
            }
            if(sum==k && k==0)
             count++;
        }
        return count;
    }
};*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int count=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int temp=sum-k;
            if(m.find(temp)!=m.end()){
                count+=m[temp];
            }
            m[sum]++;
        }
         return count;
    }
};