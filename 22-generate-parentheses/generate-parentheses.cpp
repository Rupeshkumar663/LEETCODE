class Solution {
public:
bool valid_paranthesis(string temp){
    stack<char>s;
    for(int i=0;i<temp.size();i++){
        if(s.empty() || temp[i]=='('){
            s.push(temp[i]);
        } else if(s.top()=='(' && temp[i]==')'){
            s.pop();
        }
    }
    return s.empty();
}
void Solve(string temp,vector<string>&result,int &n){
    if(temp.size()==n*2){
        if(valid_paranthesis(temp)){
            result.push_back(temp);
        }
        return;
    }
    temp.push_back('(');
    Solve(temp,result,n);
    temp.pop_back();
    temp.push_back(')');
    Solve(temp,result,n);
}
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        Solve("",result,n);
        return result;
    }
};