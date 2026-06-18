class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour%=12;
        hour*=5;
        double a=(double)minutes/60;
        a*=5;
        double b=abs((minutes*6) - (((double)hour + a)*6));
        
        double c=(180>=b)?b:(360-b);
        return c;
    }
};