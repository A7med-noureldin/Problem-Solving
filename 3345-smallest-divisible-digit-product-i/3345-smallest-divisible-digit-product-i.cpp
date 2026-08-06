class Solution {
public:
    int smallestNumber(int n, int t) {
        auto good = [&](int x) {
            int prod = 1;
            while(x){
                prod *= x%10;
                x /= 10;
            }
            return prod % t == 0;
        };
        for(int i = n; ; i++){
            if(good(i)){
                return i;
            }
        }
        return -1;
    }
};