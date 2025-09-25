class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(105, 0);
        for(auto num : nums){
            freq[num]++;
        }
        int maxi = 0, ans = 0;
        for(auto i : freq){
            if(i > maxi) maxi = i, ans = i;
            else if(i == maxi) ans += i; 
        }
        return ans;
    }
};