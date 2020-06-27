class Solution {
public:
    int numSquares(int n) {
        int k = n;
        while (!(k%4))
            k /= 4;
        if (k % 8 == 7)
            return 4;
        int i = 0;
        while (i*i < n) {
            int j = 0;
            while (j*j <= (n - i*i)) {
                if (i*i + j*j == n)
                    return (i > 0) + (j > 0);
                j++;
            }
            i++;
        }
        return 3;
    }
};

