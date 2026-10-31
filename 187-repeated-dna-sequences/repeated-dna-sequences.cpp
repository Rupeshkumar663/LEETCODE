class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        vector<string>result;
        unordered_set<string>s1;
        unordered_set<string>s2;
        int i=0,j=0;
        while(i<=(n-10)){
            int j=i;
            string temp="";
            while(j<(i+10)){
              temp.push_back(s[j]);
              j++;
            }
            if(s1.find(temp)!=s1.end()){
                s2.insert(temp);
            }
            s1.insert(temp);
            i++;
        }
        while(!s2.empty()){
            string temp=*s2.begin();
            s2.erase(temp);
            result.push_back(temp);
        }
        return result;
    }
};