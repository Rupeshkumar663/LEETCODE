class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        int mini=INT_MAX;
        sort(arr.begin(),arr.end());
        vector<vector<int>>result;
        for(int i=0;i<n-1;i++) {  
            int temp=abs(arr[i]-arr[i+1]);
            if(mini>temp) {
                mini=temp;
                result.clear();
                result.push_back({arr[i],arr[i+1]}); 
            }
            else if(mini==temp) {
                result.push_back({arr[i],arr[i+1]});
            }
        }

        return result;
    }
};