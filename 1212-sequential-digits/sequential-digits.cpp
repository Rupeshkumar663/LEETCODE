class Solution {
public:
    void solve(int num, int low, int high, vector<int>& result) {
        if(num>high)
           return;
        if(num>=low)
            result.push_back(num);
        int last=num%10;
        if(last==9)
         return;

        solve(num*10+last+1,low,high,result);
    }
    vector<int> sequentialDigits(int low,int high){
        vector<int>result;//create a vector to store number
        for(int i=1;i<=9;i++)//check all digits
            solve(i,low,high,result);
        sort(result.begin(),result.end());//sort the result in increasing order
        return result;
    }
};