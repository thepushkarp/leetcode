class Solution {
public:
    float epsilon = 0.005f;
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }
        bool colinear = true;
        vector<int> a = coordinates[0], b = coordinates[1];
        for (int i = 2; i < coordinates.size(); i++) {
            vector<int> p =coordinates[i];
            if ((p[0]-b[0]) and (p[1]-b[1])) {
                if (abs((p[0]-a[0])/(float)(p[0]-b[0]) - (p[1]-a[1])/(float)(p[1]-b[1])) > epsilon) {
                    colinear = false;
                }
            }
            else {
                if (abs((p[0]-b[0])/(float)(p[0]-a[0]) - (p[1]-b[1])/(float)(p[1]-a[1])) > epsilon) {
                    colinear = false;
                }
            }
        }
        return colinear;
    }
};
