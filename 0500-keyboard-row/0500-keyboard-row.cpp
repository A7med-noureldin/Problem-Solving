class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        // map<char, int> mp = {
        //     {'q', 1}, {'Q', 1}, {'w', 1}, {'W', 1}, {'e', 1}, {'E', 1},
        //     {'r', 1}, {'R', 1}, {'t', 1}, {'T', 1}, {'y', 1}, {'Y', 1},
        //     {'u', 1}, {'U', 1}, {'i', 1}, {'I', 1}, {'o', 1}, {'O', 1},
        //     {'p', 1}, {'P', 1},
        //     {'a', 2}, {'A', 2}, {'s', 2}, {'S', 2}, {'d', 2}, {'D', 2},
        //     {'f', 2}, {'F', 2}, {'g', 2}, {'G', 2}, {'h', 2}, {'H', 2},
        //     {'j', 2}, {'J', 2}, {'k', 2}, {'K', 2}, {'l', 2}, {'L', 2},
        //     {'z', 3}, {'Z', 3}, {'x', 3}, {'X', 3}, {'c', 3}, {'C', 3},
        //     {'v', 3}, {'V', 3}, {'b', 3}, {'B', 3}, {'n', 3}, {'N', 3},
        //     {'m', 3}, {'M', 3}
        // };
        vector<int> mp(26, 0);
        string r1 = "qwertyuiop", r2 = "asdfghjkl", r3 = "zxcvbnm";
        for (char c : r1) mp[c-'a'] = 1;
        for (char c : r2) mp[c-'a'] = 2;
        for (char c : r3) mp[c-'a'] = 3;
        for(auto word : words){
            int row = mp[tolower(word[0])-'a'];
            bool bad = false;
            for(int i = 1; i < word.size(); i++){
                if(row != mp[tolower(word[i])-'a']){
                    bad = true;
                    break;
                }
            }
            if(!bad)ret.push_back(word);
        }

        return ret;
    }
};