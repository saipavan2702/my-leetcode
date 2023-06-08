class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ash) {
        int n=ash.size();
        stack<int>st;

        vector<int>final;
        for(int i=0;i<n;i++){
            if(st.empty() or ash[i]>0)
            st.push(ash[i]);
            else {
                while(!st.empty() && st.top()>0 && abs(ash[i])>st.top())
                st.pop();

                if(!st.empty() && abs(ash[i])==st.top())
                st.pop();
                else{
                    if(st.empty() or st.top()<0)
                    st.push(ash[i]);
                }
            }
        }

        while(st.size())final.push_back(st.top()),st.pop();
        reverse(final.begin(),final.end());
        return final;
    }
};