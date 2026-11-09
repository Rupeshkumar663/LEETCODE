
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>s;
        for(int i=0;i<k;i++){
         s.insert(i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>visited(k,0);
        for(int i=0;i<arrival.size();i++){
            while(!pq.empty() && pq.top().first<=arrival[i]){
                s.insert(pq.top().second);
                pq.pop();
            }
            if(s.empty()) 
              continue;
            int target=i%k;
            auto it=s.lower_bound(target);
            if(it==s.end())
              it=s.begin();
            int server=*it;
            s.erase(it);
            visited[server]++;
            pq.push({arrival[i]+load[i],server});
        }
        int maxi=*max_element(visited.begin(),visited.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(visited[i]==maxi) ans.push_back(i);
        }
        return ans;
    }
};
