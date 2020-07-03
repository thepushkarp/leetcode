class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> cells2(8, 0);
        for (int i = 1; i < 7; i++) {
            cells2[i] = (cells[i-1] == cells[i+1]);
        }
        cells[0] = cells[7] = 0;
        N %= 14;
        if (!N)
            N = 14;
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j < 7; j++) {
                if (i&1) {
                    cells2[j] = (cells[j-1] == cells[j+1]);
                }
                else {
                    cells[j] = (cells2[j-1] == cells2[j+1]);
                }
            }
        }
        return N&1 ? cells2 : cells;
    }
};

