//T.C:O(1)
 //S.C:O(1)
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double result=0;
        double temp=minutes/12.0;
        int x=(5*hour)%60;
        temp+=x;
        result=abs((minutes-temp)*6);
        return min(result,360-result);
    }
};