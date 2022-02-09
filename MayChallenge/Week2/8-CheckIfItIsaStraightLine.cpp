class Solution {
public:
    float epsilon = 0.005f;
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }
        bool colinear = true;
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        for (int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if ((x - x1)*(y - y2) != (x - x2)*(y - y1))
                colinear = false;
        }
        return colinear;
    }
};
