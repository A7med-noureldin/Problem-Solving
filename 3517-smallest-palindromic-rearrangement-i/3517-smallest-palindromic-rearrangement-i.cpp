class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(auto c : s){
            freq[c-'a']++;
        }
        deque<char> dq;
        for(int i = 25; i >= 0; i--){
            if(freq[i]&1){
                dq.push_back(char(i+'a'));
                freq[i]--;
                break;
            }
        }

        for(int i = 25; i >= 0; i--){
            if(freq[i] == 0) continue;
            for(int j = 1; j <= freq[i]/2; j++){
                dq.push_front(char(i+'a'));
                dq.push_back(char(i+'a'));
            }
        }

        string ans = "";
        for(auto c : dq){
            ans += c;
        }
        return ans;
    }
};