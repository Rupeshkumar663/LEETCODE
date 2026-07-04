//Time Complexity-O(n)
//Space Complexity-O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      int n=bills.size();//creating a variable to store size of bill
      int five=0;//sotre five 
      int ten=0;//store ten
      for(int i=0;i<n;i++){//Traverse all bills
        if(bills[i]==5){
            five++;
        }else if(bills[i]==10){
            if(five>=1){
                five--;
                ten++;
            }else{
                return false;
            }
        }else{
            if(five>=1 && ten>=1){
                five--;
                ten--;
            }else if(five>=3){
                five-=3;
            }else{
                return false;
            }
        }
      } 
      return true; 
    }
};