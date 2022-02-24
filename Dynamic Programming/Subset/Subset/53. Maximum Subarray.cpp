#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        std::vector<int> dp(nums.size()); // dp[i] is the largest sum in nums[0:i] (including nums[i])
        dp[0] = nums[0];

        int res = nums[0]; // Used to record the largest sum
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
            res = std::max(res, dp[i]);
        }

        return res;
    }
};