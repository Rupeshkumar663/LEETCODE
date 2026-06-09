//T.C-O(N*k)-------------------------
//BRUTE FORCE----------------------
/*
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
       long long n=nums.size();
       long long result=0;
        long long i=n-1;
         while(k-- >0){
         result+=*max_element(nums.begin(),nums.begin()+i+1)-*min_element(nums.begin(),nums.begin()+i+1);
         }
        return result;
    }
};
*/
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
       long long result=0;
         result+=*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());
        return result*k;
    }
};