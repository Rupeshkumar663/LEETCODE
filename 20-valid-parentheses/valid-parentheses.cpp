//Time Complexity: O(n)
//Space Complexity: O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char>ss;
        for(int i=0;i<s.size();i++){
            if(ss.empty()){
                ss.push(s[i]);
            }else if(s[i]==')' && ss.top()=='('){
              ss.pop();
            }else if(s[i]=='}' && ss.top()=='{'){
              ss.pop();
            } else if(s[i]==']' && ss.top()=='['){
              ss.pop();
            } else {
                ss.push(s[i]);
            }
        }
        return ss.empty();
    }
};