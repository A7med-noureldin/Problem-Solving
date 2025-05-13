class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = (int) nums1.size(), n2 = (int) nums2.size();
        int x = n1 + n2;
        vector<int> ans(x);
        int i = 0, j = 0, y = 0;
        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j])ans[y] = nums1[i++];
            else ans[y] = nums2[j++];
            y++;
        }
        while(i < n1){
            ans[y++] = nums1[i++];
        }
        while(j < n2){
            ans[y++] = nums2[j++];
        }
        sort(ans.begin(), ans.end());
        double median = 0;
        if(x&1){
            return ans[x/2];
        }
        return (ans[x / 2] + ans[x / 2 - 1]) / 2.0; 
    }
};
