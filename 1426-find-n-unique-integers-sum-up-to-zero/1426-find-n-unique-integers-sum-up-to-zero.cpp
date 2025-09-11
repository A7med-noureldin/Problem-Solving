class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> nums;
        int sz = n;
        for(int i = 1; sz > 1; i++){
            nums.push_back(i);
            nums.push_back(-1*i);
            sz-=2;
        }
        if(sz)nums.push_back(0);
        return nums;
    }
};