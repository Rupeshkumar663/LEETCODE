class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        vector<bool> banned(n,false);
        int remaining=n;
        int i=0;
        while(remaining>1){
            if(banned[i]){
                i=(i+1)%n;
                continue;
            }
            char opponent=senate[i]=='R'?'D':'R';
            int j=(i+1)%n;
            while(j!=i && (banned[j] || senate[j]!=opponent)){
                j=(j+1)%n;
            }
            if(j==i)
             break;
            banned[j]=true;
            remaining--;
            i=(i+1)%n;
        }
        for(int k=0;k<n;k++){
            if(!banned[k])
                return senate[k]=='R'?"Radiant":"Dire";
        }
        return "";
    }
};