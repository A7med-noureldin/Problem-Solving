class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i = 0; i < tickets.size(); i++){
            q.push(i);
        }
        int ans = 0;
        while(!q.empty()){
            ans++;
            int f = q.front();
            q.pop();
            tickets[f]--;
            if(k==f && tickets[f]==0)
                return ans;
            if(tickets[f]!= 0)
                q.push(f);
        }
        return ans;
    }
};