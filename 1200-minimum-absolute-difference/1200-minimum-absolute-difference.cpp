class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int mn = INT_MAX;
        for(int i = 1; i < arr.size(); i++){
            mn = min(mn, arr[i]-arr[i-1]);
        }

        for(int i = 1; i < arr.size(); i++){
            if(arr[i]-arr[i-1] == mn){
                vector<int> v(2);
                v[0] = arr[i-1], v[1] = arr[i];
                ans.emplace_back(v);
            }
        }
        return ans;
    }
};