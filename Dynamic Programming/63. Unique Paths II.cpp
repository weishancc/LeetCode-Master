#include <vector>

/* Time: O(m*n), Space: O(m*n) */
/* dp[m][n] is the number of possible unique paths to the bottom-right corner
   dp[i][j] = dp[i-1][j] + dp[i][j-1] */

class Solution
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        /* Initialize the border, if there is obstacle, the value of grids after the obstacle shoulbe be marked as 0 */
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
            dp[0][j] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                /* If there is obstacle, just skip and keep its dp value to 0 */
                if (obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};