class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> v(n, 0);
        int idx = 0, flag = 1;
        for(int i = 0; i < n; i++){
            v[i] = gas[i] - cost[i];
        }
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum >= 0){
            int strt = 0, curGas = 0;
            for(int i = 0; i < n; i++){
                curGas += v[i];
                if(curGas < 0){
                    strt = i+1, curGas = 0;
                }
            }
            return strt;
        }

        return -1;
    }
};