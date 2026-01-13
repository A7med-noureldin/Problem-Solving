class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0, n = intervals.size();
        for(int i = 1; i < n; i++){
            if(intervals[i][0] < intervals[i-1][1]){
                ans++;
                intervals[i][1] = min(intervals[i][1], intervals[i-1][1]);  
            }
        }
        return ans;
    }
};