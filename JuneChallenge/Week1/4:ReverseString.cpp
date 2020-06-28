class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int first = 0, second = n - 1;
        while (first <= second) {
            char temp = s[first];
            s[first] = s[second];
            s[second] = temp;
            first++;
            second--;
        }
    }
};
