#include <vector>

/* Space: O(n) */
/* dp[i] is the number of methods to top i,
   (1) To reach top i, just climb 1 step from top i-1;
   (2) To reach top i, just climb 2 steps from top i-2;
   (3) Thus, dp[i] = dp[i-1] + dp[i-2]

   Note: Since n>=1, we don't need to initialize dp[0] */

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        std::vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};

/* Space: O(1) */
// class Solution
// {
// public:
//     int climbStairs(int n)
//     {
//         if (n <= 2)
//             return n;

//         int dp[2];
//         dp[0] = 1;
//         dp[1] = 2;

//         for (int i = 3; i <= n; i++)
//         {
//             int sum = dp[0] + dp[1];
//             dp[0] = dp[1];
//             dp[1] = sum;
//         }

//         return dp[1];
//     }
// };