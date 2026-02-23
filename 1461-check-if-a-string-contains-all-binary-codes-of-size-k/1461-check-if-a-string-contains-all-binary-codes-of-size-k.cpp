class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.size()) return false;

        unordered_set<int> st;
        int mask = (1<<k)  - 1;
        int x = 0;
        for(int i = 0; i < s.size(); i++){
            x = ((x << 1)&mask) | (s[i]-'0');
            if(i >= k-1){
                st.insert(x);
                if(st.size() == (1<<k)) return true;
            }  
        }
        return (st.size() == (1<<k));
    }
};