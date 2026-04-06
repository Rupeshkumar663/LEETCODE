/*
class Solution {
public:
    int maximum69Number (int num) {
       string s=to_string(num);
       for(int i=0;i<s.length();i++){
        if(s[i]=='6'){
            s[i]='9';
            break;
        }
       }
       return stoi(s);
    }
};
*/
class Solution {
public:
    int maximum69Number (int num) {
       int temp1=-1;
       int temp2=0;
       int temp=num;
       while(temp>0){
          if(temp%10==6){
             temp1=temp2;
          }
          temp/=10;
          temp2++;
       }
       num=num+3*pow(10,temp1);
      return num;
    }  
};