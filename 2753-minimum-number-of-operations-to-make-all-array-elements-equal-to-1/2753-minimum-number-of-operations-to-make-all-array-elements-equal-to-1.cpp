class Solution {
public:
   
    int minOperations(vector<int>& nums) {
        int num1 = 0, g = 0, n = nums.size();
        for(auto x : nums){
            num1 += (x == 1);
            g = gcd(g, x);
        }

        if(num1 > 0) return n-num1;
        if(g>1) return -1;
        
        int mini = 1e5;
         for(int i = 0; i < n; i++){
            int g = 0;
            for(int j = i; j < n; j++){
                g = gcd(g, nums[j]);
                if(g == 1){
                    mini = min(mini, j-i+1);
                    break;
                }
            }
         }
         return mini+n-2;
    }
};