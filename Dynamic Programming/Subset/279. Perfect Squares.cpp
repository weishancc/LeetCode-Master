#include <vector>
#include <algorithm>

class Solution
{
public:
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, INT_MAX); // dp[j] is least number of perfect square numbers that sum to j
        dp[0] = 0;

        for (int i = 1; i * i <= n; i++) // Iterate the stuffs
        {
            for (int j = i * i; j <= n; j++) // Iterate the bags
            {
                dp[j] = std::min(dp[j], dp[j - i * i] + 1);
            }
        }

        return dp[n];
    }
};