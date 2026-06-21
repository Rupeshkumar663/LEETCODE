/*
//T.C-O(2^N)
//S.C-O(1)
//Recursion Approach-------
class Solution {
public:
int n;
  int solve(vector<int>& costs,int coins,int idx,int count){
    if(coins==0 ||idx==n){
        return 0;
    }
    int take=0;
    if(coins>=costs[idx]){
       take=1+solve(costs,coins-costs[idx],idx+1,count);
    }
    int nottake=solve(costs,coins,idx+1,count);
    count=max(take,nottake);
    return count;
  }
    int maxIceCream(vector<int>& costs, int coins) {
       n=costs.size();
      return solve(costs,coins,0,0);
       
    }
};
*/
//T.C-O(2^N)
//S.C-O(1)
//Recursion Approach-------
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
       int n=costs.size();
       sort(costs.begin(),costs.end());
       int count=0;
       for(int i=0;i<n;i++){
        if(coins>=costs[i]){
          count++;
          coins-=costs[i];
         }
       }
      return count;
    }
};