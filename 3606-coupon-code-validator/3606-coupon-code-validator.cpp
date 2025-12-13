class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<pair<string, string>> temp;

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

        sort(temp.begin(), temp.end());

        vector<string> ans;
        for (auto& p : temp)
            ans.push_back(p.second);

        return ans;
    }
};
