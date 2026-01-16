class Solution{
public:
    vector<int>asteroidCollision(vector<int>&asteroids){
        stack<int>s;
        s.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            if(!s.empty()&&s.top()>0&&asteroids[i]<0){
                if(s.top()>-asteroids[i]){
                    continue;
                }
                else if(s.top()==-asteroids[i]){
                    s.pop();
                    continue;
                }
                else{
                    while(!s.empty()&&s.top()>0&&s.top()<-asteroids[i]){
                        s.pop();
                    }
                    if(s.empty()||s.top()<0){
                        s.push(asteroids[i]);
                    }
                    else if(s.top()==-asteroids[i]){
                        s.pop();
                    }
                }
            }
            else{
                s.push(asteroids[i]);
            }
        }
        vector<int>result;
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
