
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       int m=g.size();
       int n=s.size();
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int i=0;
       int count=0;
       for(int j=0;j<n;j++){
         if(i<m){
            if(s[j]>=g[i]){
            i++;
            count++;
            }
         }else{
            break;
         }
          
       }
       return count;
    }
};