class Solution {
public:
    int maxDifference(string s) {
        map<char, int> mp;
        int oddMax = INT_MIN;
        int evenMin = INT_MAX;

        for(auto c : s)
            mp[c]++;
        
        for(auto [x, y] : mp){
            if(y&1)
                oddMax = max(oddMax, y);
            else
                evenMin = min(evenMin, y);
        }
        return oddMax - evenMin;
    }
};