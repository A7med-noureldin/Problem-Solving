class Solution {
public:
    int longestBalanced(string s) {
        int mx = 0, n = s.size();

        for(int i = 0; i < n; i++){
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++){
                int c = s[j]-'a';
                freq[c]++;
                bool good = true;
                for(int k = 0; k < 26; k++){
                    if(freq[k] > 0 && freq[k] != freq[c]){
                        good = false;
                        break;
                    }
                }
                if(good) mx = max(mx, j-i+1);
            }
        }

        return mx;
    }
};