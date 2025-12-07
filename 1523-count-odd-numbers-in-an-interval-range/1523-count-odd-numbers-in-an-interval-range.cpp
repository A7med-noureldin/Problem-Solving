class Solution {
public:
    int countOdds(int low, int high) {
        // Odds from 1 to high -> (high+1)/2
        // odds from 1 to low-1 -> low/2
        // odds from low to high = (1->high) - (1->low-1)
        return (high+1)/2 - (low/2);
    }
};