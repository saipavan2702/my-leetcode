class Solution
{
    public:
        int garbageCollection(vector<string> &G, vector<int> &T)
        {
            int count = 0;
            int lastp = 0, lastm = 0, lastg = 0;
            for (int i = 0; i < G.size(); ++i)
            {
                for (auto c: G[i])
                {
                    count++;
                    if (c == 'M') lastm = i;
                    else if (c == 'G') lastg = i;
                    else lastp = i;
                }
            }
            for (int i = 1; i < T.size(); ++i)
            {
                T[i] += T[i - 1];
            }
            int ans = count;
            if (lastm > 0) ans += T[lastm - 1];
            if (lastg > 0) ans += T[lastg - 1];
            if (lastp > 0) ans += T[lastp - 1];
            return ans;
        }
};