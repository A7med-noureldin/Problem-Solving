class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Complexity: O(n log n)
        // Space: O(n)
        priority_queue<int> pq;
        for(auto i : nums)
            pq.push(i);
        while(k > 1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};