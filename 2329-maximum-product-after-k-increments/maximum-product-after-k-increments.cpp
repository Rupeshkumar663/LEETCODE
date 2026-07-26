class Solution {
public:
long long MOD=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        while(k--){
            int temp=pq.top();
            pq.pop();
            temp++;
            pq.push(temp);
        }
        long long multi=1;
        while(!pq.empty()){
            long long x=(long long)pq.top();
            pq.pop();
            multi=(multi*x)%MOD;
        }
         return int(multi%MOD);
      }
    };