class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n),suffix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        suffix[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            suffix[j]=min(suffix[j+1],nums[j]);
        }
        for(int i=0;i<n;i++){
            if(prefix[i]-suffix[i]<=k){
                return i;
            }
        }
        return -1;
    }
};