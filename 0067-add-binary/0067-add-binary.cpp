class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans = "";
        int carry = 0, i = 0, j = 0;
        while(i < a.size() || j < b.size() || carry){
            if(i < a.size()) carry += a[i++]-'0';
            if(j < b.size()) carry += b[j++]-'0';
            ans += (carry%2) + '0';
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};