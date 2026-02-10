class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int i = 0; i < n; i++){
            map<int, int> odd, even;
            for(int j = i; j < n; j++){
                if(nums[j]&1) odd[nums[j]]++;
                else even[nums[j]]++;

                if(odd.size() == even.size()){
                    mx = max(mx, j-i+1);
                }
            }
        }
        return mx;
    }
};