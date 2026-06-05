
//T.C-O(n*n)
//S.C-O(n)
//Brute force Aprroach----------
/*
class Solution {
public:
 long long checkwaviness(long long n){
    long long result=0;
    vector<long long>arr;
    while(n){
        arr.push_back(n%10);
        n/=10;
    }
    reverse(arr.begin(),arr.end());
    for(long long i=1;i<arr.size()-1;i++){
        if((arr[i]<arr[i-1] && arr[i]<arr[i+1]) || (arr[i]>arr[i-1] && arr[i]>arr[i+1])){
            result++;
        }
    }
    return result;
 }
    long long totalwaviness(long long num1, long long num2) {
        long long result=0;
        for(long long i=num1;i<=num2;i++){
            result+=checkwaviness(i);
        }
        return result;
    }
};
*/
class Solution {
public:
    struct Node {
        long long count;
        long long wavi;
    };
    string s;
    Node dp[17][11][11][2];
    bool visited[17][11][11][2];

    Node solve(int pos,int p2,int p1,bool started,bool t) {
        if(pos==s.size()){
            return {1,0};
        }

        if(!t && visited[pos][p2][p1][started]){
            return dp[pos][p2][p1][started];
        }

        int l=t?(s[pos]-'0'):9;
        Node result={0,0};

        for(int d=0;d<=l;d++){
            bool nt=t && (d==l);
            if(!started && d==0) {
                Node nxt=solve(pos+1,10,10,false,nt);
                result.count+=nxt.count;
                result.wavi+=nxt.wavi;
            }
            else {
                if(!started){
                    Node nxt=solve(pos+1,10,d,true,nt);
                    result.count+=nxt.count;
                    result.wavi+=nxt.wavi;
                }
                else if(p2==10){
                    Node nxt=solve(pos+1,p1,d,true,nt);
                    result.count+=nxt.count;
                    result.wavi+=nxt.wavi;
                }
                else {
                    int add =((p1>p2 && p1>d) ||(p1<p2 && p1<d));
                    Node nxt=solve(pos+1,p1,d,true,nt);
                    result.count+=nxt.count;
                    result.wavi+=nxt.wavi+nxt.count*add;
                }
            }
        }
        if(!t){
            visited[pos][p2][p1][started]=true;
            dp[pos][p2][p1][started]=result;
        }
        return result;
    }
    long long checkwaviness(long long x){
        if(x<=0) 
        return 0;
        s=to_string(x);
        memset(visited,0,sizeof(visited));
        return solve(0,10,10,false,true).wavi;
    }
    long long totalWaviness(long long num1, long long num2) {
        return checkwaviness(num2)-checkwaviness(num1-1);
    }
};