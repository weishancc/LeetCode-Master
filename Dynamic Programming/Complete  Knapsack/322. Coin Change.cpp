#include <vector>
#include <algorithm>

class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        std::vector<int> dp(amount + 1, INT_MAX); // dp[j] is the fewest number of coins to make up coin j
        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++) // Iterate the stuffs
        {
            for (int j = coins[i]; j <= amount; j++) // Iterate the bags
            {
                if (dp[j - coins[i]] != INT_MAX) // Skip the initial state of dp[j - coins[i]]
                    dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};