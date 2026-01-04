class Solution {
public:
    vector<int> getDivisors(int n){
        vector<int> div;
        for(int i = 1; i*i <= n; i++){
            if((n%i) == 0){
                if((n/i) != i) div.push_back(n/i);
                div.push_back(i);
            }
        }
        return div;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto x : nums){
            vector<int> div = getDivisors(x);
            if(div.size() == 4){
                for(auto i : div) ans += i;
            }
        }
        return ans;
    }
};