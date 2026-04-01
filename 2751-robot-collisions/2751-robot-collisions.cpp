class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<array<int, 3>> v(n); // p, d -> 0 R , 1 L, idx
        for(int i = 0; i < n; i++){
            v[i][0] = positions[i];
            v[i][1] = (directions[i] == 'L'? 1 : 0);
            v[i][2] = i;
        }

        sort(v.begin(), v.end());
        stack<int> stk; 

        
        for(int i = 0; i < n; i++){
            if(v[i][1] == 0){
                stk.push(v[i][2]);
            }
            else{
                while(!stk.empty() && healths[v[i][2]] > 0){
                    int idx = stk.top(); stk.pop();

                    if (healths[idx] > healths[v[i][2]]) {
                        healths[idx]--;
                        healths[v[i][2]] = 0;
                        stk.push(idx);
                    } 
                    else if (healths[idx] < healths[v[i][2]]) {
                        healths[v[i][2]]--;
                        healths[idx] = 0;
                    } 
                    else {
                        healths[v[i][2]] = 0;
                        healths[idx] = 0;
                    }
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(healths[i]){
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};