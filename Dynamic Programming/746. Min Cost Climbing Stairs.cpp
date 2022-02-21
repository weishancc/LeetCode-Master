#include <vector>
#include <algorithm>

/* Space: O(n) */
/* dp[i] is the cost of reaching top i,
dp[i] = min(dp[i-1], dp[i-2]) + cost[i] */
class Solution
{
public:
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        std::vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < cost.size(); i++)
            dp[i] = std::min(dp[i - 1], dp[i - 2]) + cost[i];

        return std::min(dp[cost.size() - 1], dp[cost.size() - 2]); // The last step means no cost, so we choose the smaller cost between dp[i-1] and dp[i-2]
    }
};

/* Space: O(1) */
// class Solution
// {
// public:
//     int minCostClimbingStairs(std::vector<int> &cost)
//     {
//         int dp[2];
//         dp[0] = cost[0];
//         dp[1] = cost[1];

//         for (int i = 2; i < cost.size(); i++)
//         {
//             int dpi = std::min(dp[0], dp[1]) + cost[i];
//             dp[0] = dp[1];
//             dp[1] = dpi;
//         }

//         return std::min(dp[0], dp[1]); // The last step means no cost, so we choose the smaller cost between dp[i-1] and dp[i-2]
//     }
// };