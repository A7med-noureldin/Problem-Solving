class Solution {
public:
    vector<string> ans;
    void generate(int i, int n, string curr = ""){
        if(i == n){
            if(curr != "") ans.push_back(curr), curr = "";
            return;
        }

        for(char c : {'a','b','c'}){
            if(curr.empty() || curr.back() != c){
                generate(i+1, n, curr + c);
            }
        }
    }

    string getHappyString(int n, int k) {
        generate(0, n);
        sort(ans.begin(), ans.end());
        if(k > ans.size()) return "";
        return ans[--k];
    }
};