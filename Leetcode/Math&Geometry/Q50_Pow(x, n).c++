class Solution {
public:
    double myPow(double x, int n) {
        long sign = n;
        double ans = 1.0;
        if(n < 0){
            x = 1 / x;
            sign = -sign;
        }
        while(sign > 0){
            if(sign % 2 == 1) ans *= x;
            x *= x;
            sign /= 2;
        }
        return ans;
    }
};
