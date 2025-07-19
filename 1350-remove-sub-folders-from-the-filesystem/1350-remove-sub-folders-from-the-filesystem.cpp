class Solution {
public:
    vector<bool> sub;
    map<string, int> mp;
    void dfs(string s, int j){
        for(int i= 0; i < s.size(); i++){
            if(s[i] == '/' && mp[s.substr(0, i)]){
                sub[j] = true;
                return;
            }
        }
        mp[s]++;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        int n = folder.size();
        sub = vector<bool>(n, false);
        sort(folder.begin(), folder.end());
        mp[folder[0]]++;
        for(int i= 0; i < n; i++){
            if(!sub[i]){
                dfs(folder[i], i);
            }
        }
        for(int i = 0; i < n; i++){
            if(!sub[i])ans.push_back(folder[i]);
        }
        return ans;
    }
};