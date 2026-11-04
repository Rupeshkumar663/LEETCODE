
class Solution {
public:
    multiset<int>low,high;
    long long sum_low=0,sum_high=0;

    void balance(){
        while(low.size()>high.size()+1){
            int val=*low.rbegin();
            low.erase(prev(low.end()));
            sum_low-=val;
            high.insert(val);
            sum_high+=val;
        }

        while(low.size()<high.size()){
            int val=*high.begin();
            high.erase(high.begin());
            sum_high-=val;
            low.insert(val);
            sum_low+=val;
        }
    }
    void add(int val){
        if(low.empty()||val<=*low.rbegin()){
            low.insert(val);
            sum_low+=val;
        }
        else{
            high.insert(val);
            sum_high+=val;
        }
        balance();
    }
    void remove(int val){
        auto it=low.find(val);
        if(it!=low.end()){
            low.erase(it);
            sum_low-=val;
        }
        else{
            it=high.find(val);
            high.erase(it);
            sum_high-=val;
        }
        balance();
    }
    long long getCost(){
        long long median=*low.rbegin();
        long long leftCost=median*(long long)low.size()-sum_low;
        long long rightCost=sum_high-median*(long long)high.size();
        return leftCost+rightCost;
    }

    long long minOperations(vector<int>& nums,int x,int k){
        int n=nums.size();
        vector<long long>cost(n-x+1);
        // Calculate cost of every window
        for(int i=0;i<n;i++){
            add(nums[i]);
            if(i>=x){
                remove(nums[i-x]);
            }
            if(i>=x-1){
                cost[i-x+1]=getCost();
            }
        }

        // Dynamic Programming
        const long long INF=4e18;
        vector<vector<long long>> dp(
            k+1,vector<long long>(n+1,INF)
        );
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        for(int j=1;j<=k;j++){
            for(int i=1;i<=n;i++){
                // Skip current element
                dp[j][i]=dp[j][i-1];
                // Select current window
                if(i>=x&&dp[j-1][i-x]!=INF){
                    dp[j][i]=min(
                        dp[j][i],
                        dp[j-1][i-x]+cost[i-x]
                    );
                }
            }
        }
        return dp[k][n];
    }
};
