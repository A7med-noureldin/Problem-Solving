class Solution {
public:
    int precedence(char c) {
        if(c == '+' || c == '-')
            return 1;
        else if(c == '*' || c == '/')
            return 2;
        return 0;
    }

    int evaluatePostfix(string s){
        stack<int> stk;
        int i = 0, x = 0, y = 0;
        while(i < s.size()){
            if(s[i] == ','){
                i++;
                continue;
            }
            else if(isdigit(s[i])){
                int temp = 0;
                while(isdigit(s[i]))
                    temp = temp * 10 + (s[i++] - '0');
                stk.push(temp);
            }
            else{
                y = stk.top();
                stk.pop();
                x = stk.top();
                stk.pop();
                switch(s[i++]){
                    case '+':
                        stk.push(x + y);
                        break;
                    case '-':
                        stk.push(x - y);
                        break;
                    case '*':
                        stk.push(x * y);
                        break;
                    case '/':
                        stk.push(x / y);
                        break;
                }
            }
        }
        return stk.top();
    }

    string infixToPostfix(string s){
        stack<char> stk;            
        string ret = "";
        for(int i = 0; i < s.size(); ){
            if(s[i] == ' '){
                i++;
                continue;
            }
            else if(isdigit(s[i])){
                while(isdigit(s[i]))
                    ret += s[i++];
                ret += ",";
            }
            else{
                if(stk.empty() || precedence(s[i]) > precedence(stk.top())){
                    stk.push(s[i++]);
                }
                else if(!stk.empty()){
                    ret += stk.top();
                    stk.pop();
                }
            }
        }

        while(!stk.empty()) {
            ret.push_back(stk.top());
            stk.pop();
        }
        return ret;
    }

    int calculate(string s) {
        // infix to postfix
        string postfix = infixToPostfix(s);
        // evalute infix
        return evaluatePostfix(postfix);
    }
};