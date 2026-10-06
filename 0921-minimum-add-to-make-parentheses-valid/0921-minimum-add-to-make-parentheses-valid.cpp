class Solution {
public:
    int minAddToMakeValid(string s) {
        int opened = 0;
        int ans = 0;

        for(auto c : s){
            if(c == '(') opened++;
            else{
                if(opened > 0) opened--;
                else ans++;
            }
        }
        ans += opened;
        return ans;
    }
};