class Solution {
public:
    bool checkStrings(string s, string t) {
        int n = s.size();
        map<char, int> oddS, evenS, oddT, evenT;
        for(int i = 0; i < n; i++){
            if(i&1) oddS[s[i]]++, oddT[t[i]]++;
            else evenS[s[i]]++, evenT[t[i]]++;
        }

        for(int i = 0; i < n; i++){
            if(i&1){
                if(oddS[s[i]] != oddT[s[i]]) return false; 
            }
            else{
                if(evenS[s[i]] != evenT[s[i]]) return false; 
            }
        }
        return true;
    }
};