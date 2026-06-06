//T.C-O(n)
//S.C-O(n)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
      vector<int>leftsum(n);
      vector<int>rightsum(n);
      leftsum[0]=0;
      rightsum[n-1]=0;
      for(int i=1,j=n-2;i<=n,j>=0;i++,j--){
        leftsum[i]=leftsum[i-1]+nums[i-1];
        rightsum[j]=rightsum[j+1]+nums[j+1];
      }
      nums.clear();
      for(int i=0;i<rightsum.size();i++){
          nums.push_back(abs(rightsum[i]-leftsum[i]));
      }
      return nums;
    }
};