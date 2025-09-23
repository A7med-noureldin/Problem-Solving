class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        string sv1 = "", sv2 = "";
        for(int i = 0; i < version1.size(); i++){
            if(version1[i] == '.'){
                v1.push_back(stoi(sv1));
                sv1 = "";
            }
            else sv1 += version1[i];
        }
        if(sv1 != "")v1.push_back(stoi(sv1));
        for(int i = 0; i < version2.size(); i++){
            if(version2[i] == '.'){
                v2.push_back(stoi(sv2));
                sv2 = "";
            }
            else sv2 += version2[i];
        }
        if(sv2 != "")v2.push_back(stoi(sv2));
        while(v1.size() < v2.size())v1.push_back(0);
        while(v1.size() > v2.size())v2.push_back(0);
        for(int i = 0; i < max(v1.size(), v2.size()); i++){
            if(v1[i] < v2[i]) return -1;
            if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};