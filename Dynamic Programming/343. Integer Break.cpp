#include <vector>
#include <algorithm>
#include <cmath>

/* Time: O(n^2), Space: O(n) */
/* dp[i] is the maximum product of spliting int i
   dp[i] = max(dp[i], j*(i-j), j*dp[i-j]) */
class Solution
{
public:
    int integerBreak(int n)
    {
        std::vector<int> dp(n + 1);
        dp[2] = 1;

        for (int i = 3; i <= n; i++) // Fill the dp table
        {
            for (int j = 1; j < i; j++) // Iterate j which is used to split i into (j) and (i-j)
            {
                dp[i] = std::max(dp[i], std::max(j * (i - j), j * dp[i - j])); // The first max is to find max dp[i] among j
            }
        }

        return dp[n];
    }
};