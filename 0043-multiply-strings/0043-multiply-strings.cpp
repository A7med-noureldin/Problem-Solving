class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        vector<int> mul(num1.size()+num2.size(), 0);
        for(int i = num1.size()-1; i >= 0; i--){
            for(int j = num2.size()-1; j >= 0; j--){
                int x = (num1[i]-'0') * (num2[j]-'0');
                int sum = x + mul[i+j+1];
                mul[i+j+1] = sum%10;
                mul[i+j] += sum/10;
            }
        }
        string ans = "";
        int i = 0;
        while (i < mul.size() && mul[i] == 0) i++;
        for (; i < mul.size(); i++) {
            ans += (mul[i]+'0');
        }
        return ans;
    }
};