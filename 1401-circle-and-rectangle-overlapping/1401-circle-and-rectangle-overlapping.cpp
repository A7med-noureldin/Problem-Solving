class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int x = x1; x <= x2; x++){
            for(int y = y1; y <= y2; y++){
                int distSq = abs(xCenter-x) * abs(xCenter-x) + abs(yCenter-y)*abs(yCenter-y);
                if(distSq <= (radius*radius)) return true;
            }
        }
        return false;
    }
};