class Solution {
public:
    static map<string, int> priority;

    static bool comp(const pair<string, string>& a,
                     const pair<string, string>& b) {
        if (priority[a.first] != priority[b.first])
            return priority[a.first] < priority[b.first];
        return a.second < b.second;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<pair<string, string>> temp;

        priority["electronics"] = 0;
        priority["grocery"] = 1;
        priority["pharmacy"] = 2;
        priority["restaurant"] = 3;

        set<string> businessLines = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        for (int i = 0; i < isActive.size(); i++) {
            if (!isActive[i]) continue;

            bool isvalid = true;
            if(code[i] == "") isvalid = false;
            for (char c : code[i]) {
                if ((c >= 'a' && c <= 'z') ||
                    (c >= 'A' && c <= 'Z') ||
                    (c >= '0' && c <= '9') ||
                    c == '_')
                    continue;
                isvalid = false;
                break;
            }

            if (!isvalid) continue;

            if (businessLines.count(businessLine[i])) {
                temp.push_back({businessLine[i], code[i]});
            }
        }

        sort(temp.begin(), temp.end(), comp);

        vector<string> ans;
        for (auto& p : temp)
            ans.push_back(p.second);

        return ans;
    }
};

map<string, int> Solution::priority;
