class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size(), n = nums.size();
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(nums[i]==val){
                k--; q.push(i);
            }
            else if(!q.empty()){
                int x = q.front(); q.pop();
                q.push(i);
                nums[x] = nums[i];
            }
        }
        return k;
    }
};