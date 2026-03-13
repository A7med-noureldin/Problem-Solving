class Solution {
public:
    long long findX(long long sum){
        long long l = 0, r = sqrt(2*sum)+2, ret = 0;
        while(l <= r){
            long long mid = l+(r-l)/2;
            long long ans = mid * (mid+1)/2;
            if(sum >= ans) {
                l = mid+1;
                ret = mid;
            } 
            else r = mid-1;
        }
        return ret;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e18, ans = 0;
        int n = workerTimes.size();
        while(l <= r){
            long long mid = l+(r-l)/2;
            long long can = 0;
            for(int i = 0; i < n; i++){
                long long tmp = findX(mid/workerTimes[i]);
                can += tmp;
                if(can >= mountainHeight) break;
            }

            if(can >= mountainHeight){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};