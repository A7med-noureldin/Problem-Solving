class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx = 0, sum = 0;
        for(auto x : gain){
            sum += x;
            mx = max(mx, sum);
        }
        return mx;
    }
};