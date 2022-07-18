class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sand) {
        queue<int>q;
        for(int x:s)
        q.push(x);
        
        //reverse(sand.begin(),sand.end());
        stack<int>st;
        for(int i=sand.size()-1;i>=0;i--)
        st.push(sand[i]);
        
        int i=0;
        while(q.size()!=i)
        {
            if(st.top()==q.front())
            {
                st.pop();
                q.pop();
                i=0;
            }
            else
            {
                int k;
                k=q.front();
                q.pop();
                q.push(k);
                i++;
            }
        }
        return q.size();
        
    }
};