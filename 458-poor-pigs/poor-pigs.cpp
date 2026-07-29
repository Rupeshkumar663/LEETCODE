class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int rounds=minutesToTest/minutesToDie;
        int pigs=0;
        int states=1;
        while (states<buckets){
            pigs++;
            states *=(rounds+1);
        }
        return pigs;
    }
};