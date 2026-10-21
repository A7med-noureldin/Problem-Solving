class Solution {
public:
    int minOperations(string s) {
        int n = (int)s.size();
        bool f = is_sorted(s.begin(), s.end());
        if(f) return 0;
        if(n == 2) return -1;
        char mx = 'a', mn = 'z';
        for(auto c : s) mx = max(mx, c), mn = min(mn, c);
        if(mn == s[0] || mx == s[n-1]) return 1;
        for(int i = 1; i+1 < n; i++){
            if(s[i] == mx || s[i] == mn) return 2;
        }
        return 3;
    }
};