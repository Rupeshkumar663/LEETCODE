class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Available;
        using T=tuple<long long,int,int>;
        priority_queue<T,vector<T>,greater<T>> busy;
        int n=servers.size();
        int m=tasks.size();
        vector<int>result(m);
        for(int i=0;i<n;i++){
            Available.push({servers[i],i});
        }
        long long time=0;
        for(int j=0;j<m;j++){
            time=max(time,(long long)j);
            while(!busy.empty() && get<0>(busy.top())<=time){
                auto [freeTime,weight,index]=busy.top();
                busy.pop();
                Available.push({weight,index});
            }
            if(Available.empty()){
                time=get<0>(busy.top());
                while(!busy.empty() && get<0>(busy.top())<=time){
                    auto [freeTime,weight,index]=busy.top();
                    busy.pop();
                    Available.push({weight,index});
                }
            }
            auto [weight,index]=Available.top();
            Available.pop();
            result[j]=index;
            busy.push({time+tasks[j],weight,index});
        }
        return result;
    }
};