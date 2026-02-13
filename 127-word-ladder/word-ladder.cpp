class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordbank(wordList.begin(),wordList.end());
        
        unordered_set<string>visited;
        queue<string>q;
        int count=1;
        q.push(beginWord);
        visited.insert(beginWord);
        while(!q.empty()){
            int n=q.size();
          while(n--){
             string temp=q.front();
             q.pop();
            if(temp==endWord){
                return count;
             } 
             for(char ch:"abcdefghijklmnopqrstuvwxyz"){
                    for(int i=0;i<temp.length();i++){
                        string ss=temp;
                        ss[i]=ch;
                        if(visited.find(ss)==visited.end() && wordbank.find(ss)!=wordbank.end()){
                            q.push(ss);
                            visited.insert(ss);
                        }
                    }
                } 
          }
       count++;
        }
        return 0;
    }
};