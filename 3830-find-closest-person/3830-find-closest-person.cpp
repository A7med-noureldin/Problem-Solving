class Solution {
public:
    int findClosest(int x, int y, int z) {
        int disXToZ = abs(z-x), disYToZ = abs(z-y);
        if(disXToZ < disYToZ) return 1;
        if(disXToZ > disYToZ) return 2;
        return 0;
    }
};