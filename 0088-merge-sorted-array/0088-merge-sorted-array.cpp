class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n);
        int i = 0, j = 0, idx = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j])ans[idx] = nums1[i++], idx++;
            else ans[idx] = nums2[j++], idx++;
        }
        while(i < m){
            ans[idx] = nums1[i++], idx++;
        }
        while(j < n){
            ans[idx] = nums2[j++], idx++;
        }
        nums1 = ans;
    }
};