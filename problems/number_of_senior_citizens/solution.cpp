class Solution {
public:
    int countSeniors(vector<string>& det) {
        int cnt=0;
        for(auto &x:det){
            string s=x.substr(11,2);
            int age=stoi(s);
            if(age>60)
                cnt++;
        }
        return cnt;
    }
};