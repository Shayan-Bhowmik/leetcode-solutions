class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (30*hour) + (0.5*minutes);
        double minuteAngle = 6*minutes;
    
        return  min(abs(hourAngle - minuteAngle), 360 - abs(hourAngle-minuteAngle));
    }
};