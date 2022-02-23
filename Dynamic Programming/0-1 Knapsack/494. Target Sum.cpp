#include <vector>
#include <algorithm>

class Solution
{
public:
    /* Suppose the sum of positive number is x, the sum of negative number is (sum-x)
       => x-(sum-x)=target => x=(target+sum)/2
       It's a various 0-1 knapsack problem to fill the bag with size x */
    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        int sum = 0;
        int bagSize;

        for (int num : nums)
            sum += num;
        if ((target + sum) % 2 != 0 || abs(target) > sum)
            return 0;
        else
            bagSize = (target + sum) / 2;

        std::vector<int> dp(bagSize + 1, 0); // dp[j] is the number of ways to fill the bag with size j

        /* 0-1 knapsack */
        dp[0] = 1; // 1-way to fill bag whose size is 0 (i.e., fill 0 stuffs)
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = bagSize; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]]; // It's a combination problem instead of finding max/min
            }
        }

        return dp[bagSize];
    }
};