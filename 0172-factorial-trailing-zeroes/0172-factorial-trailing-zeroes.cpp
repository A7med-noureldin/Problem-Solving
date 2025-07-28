class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0, x = 5;
        while(n/x > 0){
            ans += n/x;
            x *= 5;
        }
        return ans;
    }
};