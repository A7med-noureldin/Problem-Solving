class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if(n >= 1000) ans += n-1000+1;
        if(n >= 1'000'000) ans += n-1'000'000+1;
        if(n >= 1'000'000'000ll) ans += n-1'000'000'000ll+1;
        if(n >= 1'000'000'000'000ll) ans += n-1'000'000'000'000ll+1;
        if(n >= 1'000'000'000'000'000ll) ans += n-1'000'000'000'000'000ll+1;
        return ans;
    }
};