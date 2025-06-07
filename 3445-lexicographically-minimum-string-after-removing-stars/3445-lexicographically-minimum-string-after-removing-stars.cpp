class Solution {
public:
    string clearStars(string s) {
        string ans = "";
        map<int, bool> mp; 
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                mp[-pq.top().second] = true;
                pq.pop();
            }
            else{
                pq.push({s[i], -i});
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(mp[i] || s[i] == '*')continue;
            ans += s[i];
        }
        return ans;
    }
};