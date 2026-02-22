class Solution {
public:
    int binaryGap(int n) {
        int mx = -1;
        int prev = -1;
        for(int b = 30; b >= 0; b--){
            if((n>>b)&1){
                if(prev == -1) prev = b;
                else{
                    mx = max(mx, prev-b);
                    prev = b;
                } 
            }
        }
        return (mx == -1? 0 : mx);
    }
};