class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i = 0; i+1 < n; i++){
            if(intervals[i+1][0] > intervals[i][1]){
                ans.push_back(intervals[i]);
            }
            else {
                intervals[i+1][0] = min(intervals[i+1][0], intervals[i][0]);
                intervals[i+1][1] = max(intervals[i+1][1], intervals[i][1]);
            }
        }
        vector v = {intervals[n-1][0], intervals[n-1][1]};
        ans.push_back(v);
        return ans;
    }
};