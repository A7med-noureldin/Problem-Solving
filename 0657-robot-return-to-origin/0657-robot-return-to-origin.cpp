class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        int dx[4] = {+0, +0, -1, +1};
        int dy[4] = {+1, -1, +0, +0};
        map<char, int> mp;
        mp['R'] = 0; mp['L'] = 1; mp['U'] = 2; mp['D'] = 3;
        for(auto c : moves){
            int idx = mp[c];
            x += dx[idx], y += dy[idx];
        } 
        return (x == 0 && y == 0); 
    }
};