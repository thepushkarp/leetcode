class Solution {
public:
    int sumOfSquaredD(int n) {
        int sum = 0;
        while (n) {
            sum += pow(n%10, 2);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        while(true) {
            int sum = sumOfSquaredD(n);
            if (sum == 1) {
                return true;
            }
            else if (sum == 89) {
                return false;
            }
            n = sum;
        }
    }
};
