class Solution {
public:
    bool canBeEqual(string s, string t) {
        map<char, int> even, odd;
        for(int i = 0; i < 4; i++){
            if(i&1) odd[s[i]]++;
            else even[s[i]]++;
        }
        for(int i = 0; i < 4; i++){
            if(i&1){
                if(odd[t[i]] > 0) {
                    odd[t[i]]--;
                    continue;
                }
                return false;
            }
            else{
                if(even[t[i]] > 0){
                    even[t[i]]--;
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};