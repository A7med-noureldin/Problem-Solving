class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double maxY = 0, totArea = 0;
        for(auto s : squares){
            maxY = max(maxY,(double) s[1]+s[2]);
            totArea += (double) s[2] * s[2]; 
        }

        double l = 0, r = maxY;
        double half = totArea / 2.0;
        for (int i = 0; i < 100; i++) {
            double mid = (l + r) / 2;
            double tot = 0;

            for (const auto& s : squares) {
                if (s[1] < mid)
                    tot += s[2] * min(mid - s[1], (double)s[2]);
            }

            if (tot >= half) r = mid;
            else l = mid;
        }
        return r;
    }
};