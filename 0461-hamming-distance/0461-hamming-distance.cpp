class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamDist = 0;
        for(int i = 0; i <= 31; i++){
            int a = 1<<i;
            hamDist += ((x&a) != (y&a));
        }
        return hamDist;
    }
};