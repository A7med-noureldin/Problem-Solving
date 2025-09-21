class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = "", b = "";
        int backSps1 = 0, backSps2 = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '#'){
                backSps1++;
                continue;
            }
            if(backSps1 > 0){
                backSps1--;
                continue;
            }
            a += s[i];
        }
        for(int i = t.size()-1; i >= 0; i--){
            if(t[i] == '#'){
                backSps2++;
                continue;
            }
            if(backSps2 > 0){
                backSps2--;
                continue;
            }
            b += t[i];
        }
        return a == b;
    }
};