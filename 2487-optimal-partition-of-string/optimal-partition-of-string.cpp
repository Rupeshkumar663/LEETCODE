class Solution {
public:
    int partitionString(string s) {
     vector<int>nums(26,-1);
     int curr_start=0;
     int count=0;
     for(int i=0;i<s.size();i++){
        if(nums[s[i]-'a']>=curr_start){
            count++;
            curr_start=i;
        }
        nums[s[i]-'a']=i;
      } 
      return count+1;
    }
};