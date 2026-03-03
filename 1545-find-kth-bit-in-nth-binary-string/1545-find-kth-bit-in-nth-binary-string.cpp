class Solution {
public:
    string invertAndRevers(string s){
        int n = s.size();
        string t = s;
        for(int i = n-1, j = 0; i >= 0; i--, j++){
            t[j] = (s[i] == '0'? '1' : '0');
        }
        return t;
    }

    char findKthBit(int n, int k) {
        string s = "0";
        --n, --k;
        while(n--){
            string t = s;
            s += "1";
            s += invertAndRevers(t);
        }
        return s[k];
    }
};