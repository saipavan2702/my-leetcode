class Solution
{
    public:
        int dp[1001][2001];
    int solver(vector<vector < int>> &arr, int coins, int idx=0)
    {

       	// I have no coin and no piles
        if (idx >= arr.size() || coins == 0) return 0;

        if (dp[idx][coins] != -1) return dp[idx][coins];

        int ans = INT_MIN;

       	//Option1: I will not take anything from this pile
        ans = solver(arr, coins, idx + 1);

       	//options2: I will try to take some coins from here and other coins from some other pile ..so that I can have maximum amount

		//current pile size
        int sz = arr[idx].size();
        int sum = 0;
		
	 //[Need to iterate till min(coins,sz)because we can take only k coins  at max ]
        for (int i = 0; i < min(coins, sz); i++)
        {
            sum = sum + arr[idx][i];

           	//trying to take some coins from others also including mine
            ans = max(ans, sum + solver(arr, coins - (i + 1), idx + 1));
        }

        return dp[idx][coins] = ans;
    }
    int maxValueOfCoins(vector<vector < int>> &piles, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solver(piles, k);
    }
};