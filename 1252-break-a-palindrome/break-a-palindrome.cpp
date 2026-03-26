class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1)
          return "";
        int i=0;
        int j=n-1;
        while(i<j){
             if(palindrome[i]=='a' && palindrome[j]=='a'){
                i++;
                j--;
            }else{
                palindrome[i]='a';
                 return palindrome;
            }
        }
        palindrome[n-1]='b';
    return palindrome;
    }
};