class Solution {
public:
    bool isValid(string s) {
        if(s.size() < 3)return false;
        bool vowel = false, consonant = false, digit = false;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(auto c : s){
            if(isalpha(c)){
                if(vowels.count(c))vowel = true;
                else consonant = true;
            }
            else if(c-'0' >= 0 && c-'0' <= 9)continue;
            else return false;
        }
        return vowel && consonant;
    }
};