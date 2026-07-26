//Time Complexity: O(n+(k*logn)+(n*logn))=O(nlogn)
//Space Complexity:O(n)
class Solution {
public:
long long MOD=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());//Time Complexity:O(n*logn)
        while(k--){//Time Complexity:O(k*logn)
            int temp=pq.top();
            pq.pop();//Time Complexity:O(logn)
            temp++;
            pq.push(temp);//Time Complexity:O(logn)
        }
        long long multi=1;
        while(!pq.empty()){//Time Complexity:O(n)
            long long x=(long long)pq.top();
            pq.pop();
            multi=(multi*x)%MOD;
        }
         return int(multi%MOD);
      }
    };