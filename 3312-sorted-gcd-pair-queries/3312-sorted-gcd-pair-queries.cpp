class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(mx+1, 0);
        for(auto x : nums) cnt[x]++;
        for(int i = 1; i <= mx; i++){
            for(int j = 2*i; j <= mx; j+=i){
                cnt[i] += cnt[j]; 
            }
        }

        for(int i = 1; i <= mx; i++){
            cnt[i] = cnt[i] * (cnt[i]-1)/2;
        }
        for(int i = mx; i >= 1; i--){
            for(int j = 2*i; j <= mx; j+=i){
                cnt[i] -= cnt[j];
            }
        }
        for(int i = 1; i <= mx; i++){
            cnt[i] += cnt[i-1];
        }

        vector<int> ans;
        for(auto x : queries){
            int res = lower_bound(cnt.begin(), cnt.end(), ++x) - cnt.begin();
            ans.push_back(res);
        }
        return ans;
    }
};