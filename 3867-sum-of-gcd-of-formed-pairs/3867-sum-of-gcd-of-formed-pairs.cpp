class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);
        long long mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, (long long)nums[i]);
            v[i] = gcd(mx, nums[i]);
            cout << v[i] << " ";
        }
        cout << "\n";
        sort(v.begin(), v.end());
        long long sum = 0;
        int l = 0, r = n-1;
        while(l < r){
            sum += gcd(v[l], v[r]);
            l++, r--;
        }
        return sum;
    }
};