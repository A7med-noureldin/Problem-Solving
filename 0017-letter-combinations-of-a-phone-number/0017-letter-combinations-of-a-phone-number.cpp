class Solution {
public:
    map<int, string> mp;
    vector<string> ans;

    void backtrack(int i, string curr, string digits){
        if(i == digits.size()){
            ans.push_back(curr);
            return;
        }
        string s = mp[digits[i] - '0'];
        for(int x = 0; x < s.size(); x++){
            backtrack(i+1, curr + s[x], digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        mp[2] = "abc"; mp[3] = "def"; mp[4] = "ghi"; mp[5] = "jkl";
        mp[6] = "mno"; mp[7] = "pqrs"; mp[8] = "tuv"; mp[9] = "wxyz";

        backtrack(0, "", digits);
        return ans;    
    }
};