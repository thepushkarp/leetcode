class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int dig = digits.size() - 1;
        while (digits[dig] == 9 and dig > 0) {
            digits[dig--] = 0;
        }
        if (digits[dig] != 9) {
            digits[dig]++;
        }
        else {
            digits[dig--] = 0;
            digits.insert(digits.begin() + 0, 1);
        }
        return digits;
    }
};

