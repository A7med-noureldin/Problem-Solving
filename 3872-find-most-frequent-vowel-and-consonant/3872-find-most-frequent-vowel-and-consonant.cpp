class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> alpha(26, 0);
        for(auto c : s){
            alpha[c-'a']++;
        }
        int vowelFreq = 0, consFreq = 0;
        for(int i = 0; i <= 25; i++){
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
                vowelFreq = max(vowelFreq, alpha[i]);
            else consFreq = max(consFreq, alpha[i]);
        }
        return consFreq + vowelFreq;
    }
};