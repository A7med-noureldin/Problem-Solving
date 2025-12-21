class Solution {
public:
    bool sorted(vector<string> v){
        for(int i = 1; i < v.size(); i++){
            if(v[i] >= v[i-1]) continue;
            return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size(), m = strs.size();
        int ans = 0;
        vector<string> curr(m, "");
        for(int i = 0; i < n; i++){
            vector<string> temp(curr.begin(), curr.end());
            for(int j = 0; j < m; j++){
                temp[j] += strs[j][i];
            }

            if(sorted(temp)) curr = temp;
            else ans++;
        }
        return ans;
    }
};