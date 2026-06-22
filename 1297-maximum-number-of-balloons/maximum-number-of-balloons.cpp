//T.C-O(N)
//S.C-O(N)
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m;
        for(int i=0;i<text.size();i++){
            m[text[i]]++;
        }
        int count=INT_MAX;
        string temp="balon";
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='l' || temp[i]=='o'){
                int x=(m[temp[i]])/2;
                count=min(count,x);
            }else{
                count=min(count,m[temp[i]]);
            }
        }
        return count;
    }
};