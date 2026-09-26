class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        int n = s.size();
        string key = "";
        bool on = false;
        unordered_map<string, string> mp;

        for(auto v : knowledge){
            mp[v[0]] = v[1];
        }

        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                on = false;
                if(mp.find(key) != mp.end()) ans += mp[key];
                else ans += "?";
                key = "";
                continue;
            }
            if(s[i] == '('){
                on = true;
                continue;
            }
            if(on) {
                key += s[i];
                continue;
            }
            ans += string(1, s[i]);
        }
        return ans;
    }
};