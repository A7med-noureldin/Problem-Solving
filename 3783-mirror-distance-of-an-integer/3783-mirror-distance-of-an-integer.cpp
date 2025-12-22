class Solution {
public:
    int mirrorDistance(int n) {
        int x = 0, y = n;
        while(n > 0){
            x  = (x*10) + (n%10);
            n /= 10;
        }

        return abs(y - x);
    }
};