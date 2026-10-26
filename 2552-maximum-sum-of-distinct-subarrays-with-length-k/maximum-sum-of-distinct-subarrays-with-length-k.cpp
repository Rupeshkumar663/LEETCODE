/*class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        long long maxi=0;
        unordered_set<int>s;
        int i=0;
        int j=0;
        for(i=0;i<n;i++){
            while(s.count(nums[i])){
                s.erase((nums[j]));
                sum=sum-nums[j];
                j++;
            }
            s.insert(nums[i]);
            sum=sum+nums[i];

            if(i-j+1==k){
                maxi=max(maxi,sum);
                 s.erase(nums[j]);
                sum=sum-nums[j];
                j++;
            }
           
        }
        return maxi;
    }
};*/

/*//Time COmplexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>s;
        long long sum=0;
        long long maxi=0;
        int i=0,j=0;
        while(j<n){
            while(s.count(nums[j])){
                s.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            s.insert(nums[j]);
            sum+=nums[j];
            if(j-i+1==k){
                maxi=max(sum,maxi);
                s.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            j++;
        }
       return maxi;
    }
};*/

//Time COmplexity: O(n)
//Space Complexity: O(n)
/*class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>s;
        long long  maxi=0;
        long long sum=0;
        int i=0,j=0;
        while(s.size()!=k && j<n){
            if(s.find(nums[j])!=s.end()){
              sum-=(int)nums[i];
              s.erase(nums[i]);
              i++;
            }
            sum+=(int)nums[j];
            s.insert(nums[j]);
            j++;
        }
         if(s.size()==k)
          maxi=max(maxi,sum);
         while(j<n){
            if(s.find(nums[j])==s.end()){
              sum+=(int)nums[j];
              sum-=(int)nums[i];
              if(s.size()==k)
               maxi=max(maxi,sum);
            }
            s.erase(nums[i]);
            s.insert(nums[j]);
            i++;
            j++;
         }
         return maxi;
    }
};*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>s;
        long long  maxi=0;
        long long sum=0;
        int i=0,j=0;
         while(j<n){
            while(s.find(nums[j])!=s.end()){
                s.erase(nums[i]);
                sum-=nums[i];
                i++;
                
            }
            sum+=(int)nums[j];
            s.insert(nums[j]);
            j++;
            if(s.size()==k){
               maxi=max(maxi,sum);
               sum-=(int)nums[i];
               s.erase(nums[i]);
               i++;
            }
         }
         return maxi;
    }
};