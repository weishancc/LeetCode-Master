#include <vector>
#include <algorithm>

class Solution
{
public:
    int climbStairs(int n)
    {
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                if (i >= j)
                    dp[i] += dp[i - j];
            }
        }

        return dp[n];
    }
};