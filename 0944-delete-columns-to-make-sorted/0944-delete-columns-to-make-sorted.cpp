class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0, n = strs[0].size();
        for(int c = 0; c < n; c++){
            for(int i = 1; i < strs.size(); i++){
                if(strs[i-1][c] > strs[i][c]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};