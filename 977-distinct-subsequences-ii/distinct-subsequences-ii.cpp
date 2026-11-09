
class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;

        vector<long long> last(26, 0);

        long long dp = 1;

        for(char ch : s) {
            int idx = ch - 'a';

            long long newDp = (2 * dp - last[idx] + MOD) % MOD;

            last[idx] = dp;

            dp = newDp;
        }

        return (dp - 1 + MOD) % MOD;
    }
};
