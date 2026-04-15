class Solution {
public:
    int closestTarget(vector<string>& words, string target, int x) {
        int ans = INT_MAX, n = words.size();
        if(words[x] == target) return 0;

        for(int i = 0; i < n; i++){
            if(words[i] == target){
                ans = min(ans, min(abs(i-x), n-abs(i-x))); 
            }
        }

        return ans == INT_MAX? -1 : ans;
    }
};