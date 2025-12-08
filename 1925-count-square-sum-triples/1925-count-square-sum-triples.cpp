class Solution {
public:
    bool isInt(int x, int n){
        int l = 1, h = n;
        while(l <= h){
            int mid = l+(h-l)/2;
            if(mid*mid == x) return true;
            else if(mid*mid > x) h = mid-1;
            else l = mid+1;
        }
        return false;
    }

    int countTriples(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int x = i*i + j*j;
                if(isInt(x, n)) ans++;
            }
        }
        return ans;
    }
};