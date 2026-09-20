class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int largest=0;
        sort(nums.begin(),nums.end());
        bool check=false;
        for(int x:nums){
            sum+=x;
            if((largest+1)!=x && x!=0){
                check=true;
            }
            if(x>largest)
              largest=x;
            if(nums[0]!=0){
              return 0;
            }
        }
        if(check==false){
            return largest+1;
        }
        int temp=(largest*(largest+1))/2;
        return temp-sum;
    }
};

