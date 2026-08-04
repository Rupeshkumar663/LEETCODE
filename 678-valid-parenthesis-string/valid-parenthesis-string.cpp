//Time COmplexity: O(n)
//Space Complexity:O(1)
//by Greedy Approach-----------------
class Solution {
public:
    bool checkValidString(string s) {
      int low=0;
      int high=0;
      for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            low++;
            high++;
        }

        else  if(s[i]==')'){
            low--;
            high--;
        }
        else{
            low--;
            high++;
        }
        if(low<0)
          low=0;
        if(high<0)
          return false;
      } 
      return low==0;
    }
};