class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(nums1.size());
        int i;
        for(i = 0; i < m;i++){
            res[i] = nums1[i];
        }
        for(int j = 0; j < n; j++, i++){
            res[i] = nums2[j];
        }

        sort(res.begin(), res.end());
        nums1 = res;
    }
};