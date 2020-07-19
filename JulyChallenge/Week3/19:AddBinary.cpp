class Solution {
public:
    static void padding(string &a, string &b) {
        if (a.size() < b.size()) {
            for (int i = a.size(); i < b.size(); i++) {
                a = '0' + a;
            }
        }
        else {
            for (int i = b.size(); i < a.size(); i++) {
                b = '0' + b;
            }
        }
    }
    string addBinary(string a, string b) {
        char carry = '0';
        if (a.size() != b.size()) {
            padding(a, b);
        }
        int n = a.size();
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            char c = '0' + int(((a[i] - '0') + b[i] - '0' + (carry - '0'))%2);
            carry = '0' + int(((a[i] - '0') + b[i] - '0' + (carry - '0')) > 1);
            ans = c + ans;
        }
        if (carry == '1') {
            ans = '1' + ans;
        }
        return ans;
    }
};
