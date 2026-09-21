class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        unordered_map<int,int>m;

        for(int i=0;i<n;i++){
            m[tasks[i]]++;
        }

        int count=0;

        for(auto x:m){
            int temp=x.second;

            if(temp==1){
                return -1;
            }

            count+=temp/3;

            if(temp%3!=0){
                count++;
            }
        }

        return count;
    }
};