class Solution {
public:
    int arrangeCoins(int n) {
        return (long(sqrt(long(8)*n + 1)) - 1)/2;
    }
};

