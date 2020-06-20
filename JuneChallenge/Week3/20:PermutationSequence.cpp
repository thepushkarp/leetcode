class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(1, 1);
        for (int i = 1; i <= n; i++) {
            fact.push_back(fact[i - 1] * i);
        }
        string res = "";
        vector<char> chars(n);
        int pos;
        k--;
        for (int i = 0; i < n; i++)
            chars[i] = '0' + i + 1;
        while (--n) {
            pos = k / fact[n];
            res += chars[pos];
            chars.erase(begin(chars) + pos);
            k %= fact[n];
        }
        return res;
    }
};

