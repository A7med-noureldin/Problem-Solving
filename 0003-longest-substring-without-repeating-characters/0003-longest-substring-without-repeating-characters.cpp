class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(128, 0);
        int l = 0, r = 0, n = s.size(), maxi = 0;

        while (r < n) {
            if (vis[s[r]])
                while (vis[s[r]]) vis[s[l]] = 0, l++;
            vis[s[r]] = 1;
            maxi = max(maxi, r-l+1), r++;
        }
        return maxi;
    }
};
