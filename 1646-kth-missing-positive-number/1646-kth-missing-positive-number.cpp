class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        long long l = 0, r = arr.size()-1;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            long long missing = arr[mid] - (mid+1);
            if(missing < k) l = mid + 1;
            else r = mid - 1;
        }
        return l + k;
    }   
};