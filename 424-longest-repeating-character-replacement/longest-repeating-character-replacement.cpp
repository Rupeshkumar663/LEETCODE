/*class Solution {
public:
    int characterReplacement(string s, int k) {
        int result=0;
        for(int i=0;i<s.size();i++){
            vector<int>temp(26);
            int maxi=0;
            for(int j=i;j<s.size();j++){
               temp[s[j]-'A']=temp[s[j]-'A']+1;
                maxi=maxi>temp[s[j]-'A']?maxi:temp[s[j]-'A'];
                int ops=(j-i+1)-maxi;
                if(ops>k){
                    break;
                }
                result=max(result,(j-i+1));
            }
        }
        return result;
    }
};*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int result=0;
        int i=0;
        int j=0;
        vector<int>temp(26);
        int maxi=0;
        while(j<n){
         temp[s[j]-'A']=temp[s[j]-'A']+1;
         maxi=maxi>temp[s[j]-'A']?maxi:temp[s[j]-'A'];
         int ops=(j-i+1)-maxi;
         while(ops>k){
            temp[s[i]-'A']--;
            i++;
            int z=*max_element(temp.begin(),temp.end());
            maxi=maxi>z?maxi:z;
            ops=(j-i+1)-maxi;
          }
          result=max(result,(j-i+1));
          j++;
        }
        return result;
    }
};