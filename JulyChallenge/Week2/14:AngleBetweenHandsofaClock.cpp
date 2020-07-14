class Solution {
public:
    double angleClock(int hour, int minutes) {
        float hourAngle = (hour % 12)*30 + minutes*0.5;
        float minAngle = (minutes)*6;
        float ang = abs(hourAngle - minAngle);
        return min(ang, 360 - ang);
    }
};

