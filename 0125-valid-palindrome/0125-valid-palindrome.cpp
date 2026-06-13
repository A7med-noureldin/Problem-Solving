class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(auto c : s){
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isdigit(c)) t += tolower(c);
        }
        int i = 0, j = t.size()-1;
        while(i <= j){
            if(t[i] != t[j]) return false;
            i++, j--;
        }
        return true;
    }
};