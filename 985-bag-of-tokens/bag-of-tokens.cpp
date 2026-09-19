class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        int ans=0;
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                ans=max(ans,score);
                power-=tokens[i];
                i++;
            }
            else if(score>=1 && i<j){
                score--;
                power+=tokens[j];
                j--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};