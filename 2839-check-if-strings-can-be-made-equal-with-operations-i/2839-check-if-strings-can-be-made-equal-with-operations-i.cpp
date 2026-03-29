class Solution {
public:
    bool canBeEqual(string s, string t) { 
        for(int i = 0; i < 2; i++){
            if(s[i] != t[i]) swap(s[i], s[i+2]);
        }
        
        return s == t;
    }
};