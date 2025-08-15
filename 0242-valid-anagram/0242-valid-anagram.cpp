class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alphabet(26, 0), alphabet2(26, 0);
        for(auto c : s)
            alphabet[c-'a']++;
        for(auto c : t)
            alphabet2[c-'a']++;
        for(auto c : s){
            if(alphabet[c-'a'] == alphabet2[c-'a'])continue;
            return false;
        }
        return s.size() == t.size();
    }
};