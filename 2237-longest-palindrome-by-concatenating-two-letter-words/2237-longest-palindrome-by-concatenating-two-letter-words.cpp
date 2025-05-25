class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        int ans = 0, pal = 0;
        for(auto c : words) mp[c]++;

        for(auto &[w, f] : mp){
            string s = w;
            reverse(s.begin(), s.end());
            if(w == s){
                ans += (f / 2) * 4;
                if(f % 2)pal = 1;
            }
            else if(mp.count(s) && s < w) ans += (4 * min(mp[s], f));
        }
        ans += (pal? 2 : 0); // in case of odd freq in palindrome words
        // aa aa aa aa aa => 
        return ans;   
    }
};