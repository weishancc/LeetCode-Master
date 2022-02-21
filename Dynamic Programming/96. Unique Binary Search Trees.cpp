#include <vector>

/* Time: O(n^2), Space: O(n) */
/* dp[i] is the number of structurally unique BST's of i
   dp[i] += dp[j - 1] * dp[i - j]; */

class Solution
{
public:
    int numTrees(int n)
    {
        std::vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) // i can be considered how many nodes in the tree
        {
            /* j as root iterated from i to n, when j=1 there is no leftSubtree, when j=i, there is no rightSubtree */
            /* dp[i] += dp[the number of nodes in leftSubree w/ root j] * dp[the number of nodes in rightSubree w/ root j] */
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};
