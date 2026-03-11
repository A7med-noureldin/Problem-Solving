class Solution {
public:
    int findComplement(int n) {
        int st = 0;
        if(n == 0) return 1;
        for(int b = 30; b >= 0; b--){
            if(n&(1<<b)) st = 1;
            if(st) n ^= (1<<b);
        }
        return n;
    }
};