
//T.C-O(n*n)
//S.C-O(n)
//Brute force Aprroach----------
class Solution {
public:
 int checkwaviness(int n){
    int ans=0;
    vector<int>arr;
    while(n){
        arr.push_back(n%10);
        n/=10;
    }
    reverse(arr.begin(),arr.end());
    for(int i=1;i<arr.size()-1;i++){
        if((arr[i]<arr[i-1] && arr[i]<arr[i+1]) || (arr[i]>arr[i-1] && arr[i]>arr[i+1])){
            ans++;
        }
    }
    return ans;
 }
    int totalWaviness(int num1, int num2) {
        int result=0;
        for(int i=num1;i<=num2;i++){
            result+=checkwaviness(i);
        }
        return result;
    }
};