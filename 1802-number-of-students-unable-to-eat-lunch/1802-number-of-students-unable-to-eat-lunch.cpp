class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sand) {
        int i = 0; // idx of sandwiches
        queue<int> q;
        int c = 0;
        for(auto x : students){
            q.push(x);
        }
        
        while(!q.empty()){
            if(q.front() == sand[i]){
                q.pop();
                i++, c = 0; 
            }
            else{
                q.push(q.front());
                q.pop();
                c++;
            }
            if(c == q.size())break; // if we skipped all students so no one needs this sandwich
        }
        return q.size();
    }
};