class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int count = 0;
        for(auto a : apple) count += a;
        int ans = 0;
        for(auto c : capacity){
            if(count <= 0) break;
            count -= c;
            ans++;
        }
        return ans;
    }
};