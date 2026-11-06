//Time Complexity: O(l*q)
//Space Complexity: (n)
/*class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int>result;
        for(int i=0;i<queries.size();i++){
            int count=0;
            int start=queries[i]-x;
            int end=queries[i];
            unordered_set<int>s;
            for(int j=0;j<logs.size();j++){
                if(logs[j][1]>=start && logs[j][1]<=end){
                    s.insert(logs[j][0]);
                }
            }
            result.push_back(n-s.size());
        }
        return result;
    }
};*/

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int m=queries.size();
        vector<pair<int,int>>q;
        for(int i=0;i<m;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        vector<int>result(m);
        unordered_map<int,int>mp;
        int l=0,r=0;
        int Active=0;
        for(auto [time,idx]:q){
            int start=time-x;
            while(r<logs.size() && logs[r][1]<=time){
                int id=logs[r][0];
                if(mp[id]==0) Active++;
                mp[id]++;
                r++;
            }
            while(l<r && logs[l][1]<start){
                int id=logs[l][0];
                mp[id]--;
                if(mp[id]==0){
                    Active--;
                    mp.erase(id);
                }
                l++;
            }
            result[idx]=n-Active;
        }
        return result;
    }
};