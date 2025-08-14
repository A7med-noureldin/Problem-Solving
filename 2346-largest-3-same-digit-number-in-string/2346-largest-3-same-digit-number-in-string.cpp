class Solution {
public:
    string largestGoodInteger(string num) {
        vector<int> exist(10, 0);
        for(auto c : num){
            exist[c-'0']++;
        }
        for(int i = 9; i >= 0; i--){
            if(exist[i] == 0)continue;
            for(int j = 0; j+2 < num.size(); j++){
                if(num[j] == num[j+1] && num[j] == num[j+2] && (num[j]-'0') == i)
                    return num.substr(j, 3);
            }
        }
        return "";
    }
};