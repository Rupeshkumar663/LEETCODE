//Time Complexity-O(nlogn)
//Space Complexity-O(1)
//Greedy Approach-------------
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       int m=g.size();
       int n=s.size();
       //sorting greed factors and cookies size in ascending order
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int i=0;//it reperesent current child
       int count=0;//store maximum number of content 
       for(int j=0;j<n;j++){//traverse all cookies
         if(i<m){
            if(s[j]>=g[i]){// if satisfied this condition then count
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