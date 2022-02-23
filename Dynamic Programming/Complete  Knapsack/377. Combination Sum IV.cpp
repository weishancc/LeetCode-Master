#include <vector>
#include <algorithm>

class Solution
{
public:
    int combinationSum4(std::vector<int> &nums, int target)
    {
        std::vector<int> dp(target + 1, 0); // dp[j] is the number of ways of combination whose sum is j
        dp[0] = 1;

        for (int i = 0; i <= target; i++) // Iterate the bags
        {
            for (int j = 0; j < nums.size(); j++) // Iterate the stuffs
            {
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) // Different w/ (518.), it's a permutation problem
                    dp[i] += dp[i - nums[j]];
            }
        }

        return dp[target];
    }
};