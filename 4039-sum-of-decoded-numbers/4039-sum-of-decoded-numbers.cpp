class Solution {
public:

    long long power(long long x, long long y, long long MOD) {
        long long ans = 1;

        while (y > 0) {
            if (y % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            y = y / 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        const long long MOD = 1000000007;

        vector<long long> v = nums;

        long long ans = 0;

        for (long long num : v) {
            int width = num % 10;
            long long d = num / 10;

            string s = to_string(d);

            string xs = s.substr(0, width);
            string ys = s.substr(width);

            long long x = stoll(xs);
            long long y = stoll(ys);

            long long value = power(x, y, MOD);

            ans = (ans + value) % MOD;
        }

        return ans;
    }
};