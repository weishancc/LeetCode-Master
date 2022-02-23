#include <vector>
#include <algorithm>

class Solution
{
public:
    bool canPartition(std::vector<int> &nums)
    {
        std::vector<int> dp(10001, 0); // The sum of elements in nums is smaller than (200*100), the maximum size of bag need (200*100/2)
        int sum = 0;
        for (int num : nums)
            sum += num;

        /* When the bag is fully packed, we can find subsets whose sum equals to (sum/2), and vice versa */
        int target = sum / 2;

        if (sum % 2 == 1)
            return false;

        /* 0-1 knapsack */
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        /* The elements in nums can constitute the subsets whose sum equals to target */
        if (dp[target] == target)
            return true;
        return false;
    }
};