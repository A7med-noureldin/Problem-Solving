class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)return "0";
        string ans = "";
        if((numerator < 0) ^ (denominator < 0)) ans += "-"; // sign
        //int part
        long num = labs((long long)numerator);
        long deno = labs((long long)denominator);
        long l = num / deno;
        ans += to_string(l);
        long long remainder = num % deno;
        if(remainder == 0)return ans;

        // Fractional part
        ans += ".";
        unordered_map<long, int> mp;
        // Long division sim.
        while(remainder != 0){
            if(mp.count(remainder)){
                ans.insert(mp[remainder], "(");
                ans += ")";
                return ans;
            }
            mp[remainder] = ans.size();
            remainder *= 10;
            ans += to_string(remainder/deno);
            remainder %= deno;
        }
        return ans;
    }
};