class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt = 0, n = s.size();
        int zeros = 0, ones = 0;
        int l = 0, r = 0;
        int c = (int)s[0]-'0';
        while(r < n){
            while(r < n && s[r] == (c+'0')){
                zeros += (s[r] == '0'), ones += (s[r] == '1'), r++;
            }
            c = 1-c;
            while(r < n && s[r] == (c+'0')){
                zeros += (s[r] == '0'), ones += (s[r] == '1'), r++;
            }
            cnt += min(zeros, ones);
            if(c) zeros = 0;
            else ones = 0;
        }
        return cnt;
    }
};