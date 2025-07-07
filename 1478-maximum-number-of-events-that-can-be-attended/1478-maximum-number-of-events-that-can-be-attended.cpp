class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0, n = events.size(), i = 0, d = 0;
        while(i < n || !pq.empty()){
            if(pq.empty())d = events[i][0];
            while (i < n && events[i][0] == d)
                pq.push(events[i++][1]);
            while (!pq.empty() && pq.top() < d)
                pq.pop();
            if(!pq.empty()){
                pq.pop();
                ans++, d++;
            }
        }
        return ans;
    }
};