class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> freq(1e4+5, 0);
        for(auto x : nums){
            freq[x]++;
            if(freq[x] > 1) return x;
        }
        return -1;
    }
};