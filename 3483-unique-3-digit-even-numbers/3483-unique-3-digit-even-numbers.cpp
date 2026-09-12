class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<bool> vis(1000, false);
        int n = digits.size(), ans = 0;

        auto valid = [&](int x){
            int tmp = x, d = 0;
            while(tmp) tmp /= 10, d++;
            return !vis[x] && d == 3 && !(x&1);
        };

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j) continue;
                    int num = digits[i]*100+digits[j]*10+digits[k];
                    if(valid(num))ans++, vis[num] = true;
                }
            }
        }
        return ans;
    }
};