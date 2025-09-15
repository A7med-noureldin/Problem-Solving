class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> broken(26, 0);
        int typedWords = 0;
        for(auto c : brokenLetters){
            broken[c-'a']++;
        }

        int i = 0;
        bool isbroken = false;
        while(i < text.size()){
            isbroken = false;
            while(i < text.size() && text[i] != ' '){
                if(broken[text[i]-'a'] > 0){ //broken
                    isbroken = true;
                }
                i++;
            }
            if(!isbroken)typedWords++;
            i++;
        }
        return typedWords;
    }
};