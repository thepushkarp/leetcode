class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int power = 0;
        int n = num?floor(log(num)/log(2)):0;
        while (n >= 0) {
            int powr = pow(2, n);
            if (!(num/powr)) {
                ans += (1 << n);
            }
            else {
                num -= powr;
            }
            --n;
        }
        return ans;
    }
};
