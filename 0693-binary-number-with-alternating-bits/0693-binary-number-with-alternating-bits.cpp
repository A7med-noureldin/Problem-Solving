class Solution {
public:
    int getLast(int n){
        for(int i = 30; i >= 0; i--){
            if(n&(1<<i)) return i;
        }
        return 0;
    }

    bool hasAlternatingBits(int n) {
        int x = getLast(n);
        for(int i = 1; i <= x; i++){
            int prev = (n&(1<<(i-1))) != 0;
            int curr = (n&(1<<i)) != 0;
            if(prev == curr) return 0;
        }
        return 1;
    }
};