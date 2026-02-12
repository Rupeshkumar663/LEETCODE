class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankset(bank.begin(),bank.end());
        unordered_set<string>visited;
        queue<string>q;
        q.push(startGene);
        visited.insert(startGene);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string temp=q.front();
                q.pop();
                if(temp==endGene){
                    return level;
                }

                for(char ch:"ACGT"){
                    for(int i=0;i<temp.size();i++){
                        string s=temp;
                        s[i]=ch;

                        if(visited.find(s)==visited.end() && bankset.find(s)!=bankset.end()){
                            visited.insert(s);
                            q.push(s);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};