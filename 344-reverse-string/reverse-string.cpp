//Time Complexity: O(n)
//Space Complexity: O(1)
/*class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
           char temp=s[i];
           s[i]=s[j];
           s[j]=temp;
           i++;
           j--;
        }
    }
};*/

//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
   void Solve(vector<char>& s,int i){
    if(i>=s.size()){
        s.clear();
        return;
    }
    char temp=s[i];
    Solve(s,i+1);
    s.push_back(temp);
   }
    void reverseString(vector<char>& s) {
        Solve(s,0);
    }
};