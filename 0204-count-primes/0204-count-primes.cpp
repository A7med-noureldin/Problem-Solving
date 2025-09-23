class Solution {
    const int N = 5e6;
    vector<bool> primes; 
public:
    Solution() : primes(N, true) {}
    int seive(int n){
        primes[0] = primes[1] = false;
        for(int i = 2; i*i < n; i++){
                if(!primes[i])continue;
                for(long long j = i*i; j < n; j+=i)
                    primes[j] = false;
        }
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(primes[i])
                ans++;
        }
        return ans;
    }

    int countPrimes(int n) {
        if(n <= 1) return 0;
        return seive(n);
    }
};