#include <vector>
#include <algorithm>

class Solution
{
public:
    /* We firstly separate the stones into two stacks whose weights are close, then we can get the min weight
       after sum minus these two stacks' weights */
    int lastStoneWeightII(std::vector<int> &stones)
    {
        std::vector<int> dp(1501, 0); // dp[j] is the maximum weight of bag size j
        int sum = 0;
        for (int stone : stones)
            sum += stone;

        int target = sum / 2;

        /* 0-1 knapsack */
        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = target; j >= stones[i]; j--)
            {
                dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[target] - dp[target];
    }
};