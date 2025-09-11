class Solution {
public:
    bool isVowel(char c){
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' ||c == 'U' ||c == 'a' ||c == 'e' ||
               c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string &s) {
        string vowels = "AEIOUaeiou";
        map<char, int> mp;
        for(auto c : s){
            if(isVowel(c)){
                mp[c]++;
            }
        }
        
        int i = 0;
        for(auto &c : s){
            if(isVowel(c)){
                while(mp[vowels[i]] == 0)i++;
                mp[vowels[i]]--;
                c = vowels[i];
            }
        }
        return s;
    }
};