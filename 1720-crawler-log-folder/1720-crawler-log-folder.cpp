class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stk;
        for(auto log : logs){
            if(log == "./")continue;
            else if(log == "../"){
                if(!stk.empty())stk.pop();
            }
            else{
                stk.push("a");
            }
        }
        return (int) stk.size();
    }
};