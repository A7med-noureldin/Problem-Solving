class Solution {
public:
    bool isNonZero(int i){
        while(i){
            if(i%10==0)return false;
            i/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            if(isNonZero(i) && isNonZero(n-i)){
                return {i, n-i};
            }
        }
        return {0, 0};
    }
};