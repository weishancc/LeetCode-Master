#include <vector>
#include <algorithm>

class Solution
{
public:
    int change(int amount, std::vector<int> &coins)
    {
        std::vector<int> dp(amount + 1, 0); // dp[j] is the number of ways to collect j

        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) // Iterate the coins
        {
            for (int j = coins[i]; j <= amount; j++) // Iterate the bags
            {
                dp[j] += dp[j - coins[i]]; // It's a combination problem instead of permutation, e.g., (1+1+2) and (2+1+1) is the same
            }
        }

        return dp[amount];
    }
};