class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        --k;
        while(s.size() <= k){
            string t = s;
            for(int i = 0; i < t.size(); i++){
                t[i]++;
            }
            s += t;
        }
        return s[k];
    }
};