class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> h(n, 1);
        int i,j ,k ;
        i = j = k = 0;
        for (int l = 1; l < n; l++) {
            h[l] = min({2*h[i], 3*h[j], 5*h[k]});
            if (2*h[i] == h[l]) {
                i++;
            }
            if (3*h[j] == h[l]) {
                j++;
            }
            if (5*h[k] == h[l]) {
                k++;
            }
        }
        return h[n-1];
    }
};
