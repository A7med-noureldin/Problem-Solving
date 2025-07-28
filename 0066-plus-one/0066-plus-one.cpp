class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1;
        while(idx >= 0 && digits[idx] == 9){
            digits[idx--] = 0;
        }
        vector<int> ans(digits.size() + 1, 0);
        if(idx < 0){
            ans[0] = 1;
            for(int i = 0; i < digits.size(); i++){
                ans[i+1] = digits[i];
            }
            return ans;
        }
        digits[idx]++;
        return digits;
    }
};