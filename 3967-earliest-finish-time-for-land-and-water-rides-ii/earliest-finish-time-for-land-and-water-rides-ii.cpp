//T.C-O(n*m)
//S.C-O(1)
//Brute force Approach----------------
/*
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int result=1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp1=max(landStartTime[i]+landDuration[i],waterStartTime[j])+waterDuration[j];
                int temp2=max(waterStartTime[j]+waterDuration[j],landStartTime[i])+landDuration[i];
                result=min(result,min(temp1,temp2));
            }
        }
        return result;
    }
};
*/
//T.c-O(n)
//S.C-O(1)
//optimal Approach----------------
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int result=1e9;
        int minland=1e9;
        for(int i=0;i<n;i++){
           minland=min(minland,(landStartTime[i]+landDuration[i]));
        }
        for(int j=0;j<m;j++){
            int temp=max(minland,waterStartTime[j]);
            int dist=waterDuration[j];
             result=min(result,temp+dist);
        }
        int minwater=1e9;
         for(int i=0;i<m;i++){
           minwater=min(minwater,(waterStartTime[i]+waterDuration[i]));
        }
        for(int j=0;j<n;j++){
            int temp=max(minwater,landStartTime[j]);
            int dist=landDuration[j];
             result=min(result,temp+dist);
        }
        return result;
    }
};