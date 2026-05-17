class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        auto bs = [&](int l, int r, int x) ->int{
            while(l <= r && r < n){
                int mid = l + (r-l)/2;
                if(nums[mid] >= x) r = mid-1;
                else l = mid+1;
            }
            return l;
        };

        int ans = 0;
        for(int i = 0; i+2 < n; i++){
            if(nums[i] == 0) continue;
            for(int j = i+1; j+1 < n; j++){
                int idx = bs(i+2, n-1, nums[i]+nums[j]);
                ans += idx-j-1;
            }
        }
        return max(ans, 0);
    }
};