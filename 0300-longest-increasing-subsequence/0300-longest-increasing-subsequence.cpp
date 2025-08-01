class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        vector<int> v;
        v.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= v.back()){
                int l = 0, r = v.size()-1;
                while(l <= r){
                    int mid = (l + r)/2;
                    if(v[mid] == nums[i]){
                        l = mid;
                        break;
                    }
                    else if(v[mid] > nums[i]) r = mid-1;
                    else l = mid+1;
                }
                v[l] = nums[i];
            }
            else{
                v.push_back(nums[i]);
                ans = max(ans, (int)v.size());
            }
        }
        ans = max(ans, (int)v.size());
        return ans;
    }
};