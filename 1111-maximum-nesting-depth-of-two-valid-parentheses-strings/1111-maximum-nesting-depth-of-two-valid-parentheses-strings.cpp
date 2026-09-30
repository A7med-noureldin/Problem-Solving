class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size(), op = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(seq[i] == '(') {
                ans.push_back((++op)%2);
            }
            else{
                ans.push_back(op--%2);
            }
        }
        return ans;
    }
};