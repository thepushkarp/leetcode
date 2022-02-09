class Solution {
public:
    string stripLeadingZeros(string str) {
        int i = 0;
        for (; i < str.size() - 1; i++) {
            if (str[i] != '0') break;
        }
        str.erase(str.begin(), str.begin() + i);
        return str;
    }

    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";

        int digitsToKeep = num.size() - k;

        string ans = "";
        int lastIndex = -1;
        while (digitsToKeep) {
            int mini = 10;
            for (int i = lastIndex + 1; i <= num.size() - digitsToKeep; i++) {
                if (num[i] - '0' < mini) {
                    mini = num[i] - '0';
                    lastIndex = i;
                }
            }
            ans+=('0' + mini);
            digitsToKeep--;
        }
        return stripLeadingZeros(ans);
    }
};
