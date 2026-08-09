class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordBank(wordList.begin(),wordList.end());
        unordered_set<string>visited;
        queue<string>q;
        q.push(beginWord);
        visited.insert(beginWord);
        int count=1;
        while(!q.empty()){
          int t=q.size();
          while(t--){
            string temp1=q.front();
            q.pop();
            if(temp1==endWord){
                return count;
            }
            for(auto ch:"abcdefghijklmnopqrstuvwxyz"){
                for(int i=0;i<temp1.size();i++){
                    string temp2=temp1;
                    temp2[i]=ch;
                    if(visited.find(temp2)==visited.end() && wordBank.find(temp2)!=wordBank.end()){
                        visited.insert(temp2);
                        q.push(temp2);
                    }
                }
            }
          }
          count++;
        }
       return 0;
    }
};