#include <vector>

/* Time: O(m*n), Space: O(m*n) */
/* dp[m][n] is the number of possible unique paths to the bottom-right corner
   dp[i][j] = dp[i-1][j] + dp[i][j-1] */
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        /* Initialize the border */
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

/* Time: O(m), Space: O(1) */
/* Combination problem: C(n-1 + m-1, n-1) = C(m+n-2, n-1) = (m+n-2)!/ */
// class Solution
// {
// public:
//     int uniquePaths(int m, int n)
//     {
//         long long numerator = 1; // 分子
//         int denominator = m - 1; // 分母
//         int count = m - 1;
//         int t = m + n - 2;
//         while (count--)
//         {
//             numerator *= (t--);
//             while (denominator != 0 && numerator % denominator == 0)
//             {
//                 numerator /= denominator;
//                 denominator--;
//             }
//         }
//         return numerator;
//     }
// };