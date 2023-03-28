class Solution {
public:
    int getNextDaysIdx(vector<int>&days, int daysIdx, int ticketDuration)
    {
        int target = days[daysIdx] + ticketDuration - 1;
        for (int i = daysIdx + 1; i < days.size(); i++)
        {
            if (days[i] > target) return i;
        }
        return days.size();
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n = days.size();
        vector<int>ticketDurations = {1, 7, 30};
        vector<int>dp(n);
        //If I start at last day I can pick the min cost ticket instead of taking ticket for '1' day duration
        dp[n - 1] = *min_element(costs.begin(), costs.end()); 
        for (int currDaysIdx = n - 2; currDaysIdx >= 0; currDaysIdx--)
        {
            int minTravelCost = INT_MAX;
            //=================================================================
            for (int i = 0; i < 3; i++)
            {
                int ticketCost = costs[i], ticketDuration = ticketDurations[i];
                int nextDaysIdx = getNextDaysIdx(days, currDaysIdx, ticketDuration);
                
                int nextTravelCost = (nextDaysIdx >= n)? 0 : dp[nextDaysIdx];
                int travelCost = ticketCost + nextTravelCost;
                minTravelCost = min(minTravelCost, travelCost);
            }
            //======================================================================
            dp[currDaysIdx] = minTravelCost;
        }
        return dp[0];
    }
};