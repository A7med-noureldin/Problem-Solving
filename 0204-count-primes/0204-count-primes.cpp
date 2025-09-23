class Solution {
    const int N = 5*1e6;
    vector<int> primes; 
public:
    Solution() : primes(N, 1) {}
    int seive(int n){
        primes[0] = primes[1] = 0;
        for(int i = 2; i*i < n; i++){
                for(long long j = i*i; j < n; j+=i)
                    primes[j] = 0;
        }
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(primes[i])
                ans++;
        }
        return ans;
    }

    int countPrimes(int n) {
        return seive(n);
    }
};