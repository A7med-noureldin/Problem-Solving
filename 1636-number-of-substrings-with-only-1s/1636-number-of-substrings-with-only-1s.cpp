class Solution {
public:
    int numSub(string s) {
        long long temp = 0, ans = 0;
        long long mod = 1e9 + 7;
        int i = 0, n = s.size();
        while(i < n){
           if(s[i] == '1'){
                temp++;
                ans = (ans+temp)%mod;
           }
           else temp = 0;
           i++;
        }
        return ans;
    }
};