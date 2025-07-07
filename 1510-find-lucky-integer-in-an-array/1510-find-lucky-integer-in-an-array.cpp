class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> v(510, 0);
        for(auto i : arr)
            v[i]++;
        int maxi = -1;
        for(int i = 500; i >= 1; i--){
            if(v[i] > 0 && v[i] > maxi && v[i] == i)maxi = i;
        }
        return (maxi == -1? -1 : maxi);
    }
};