#include <vector>
#include <algorithm>

class Solution
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        std::vector<int> dp(nums.size(), 1); // dp[i] is the length of the longest strictly increasing subsequence in nums[0:i+1]

        if (nums.size() == 1)
            return 1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = std::max(dp[i], dp[j] + 1); // +1 because the current element is chosen
            }
        }

        /* dp[nums.size()-1] is the longest subsequence including the last element,
           so we need to return the maximum in dp table instead of dp[nums.size()-1] */
        int res = *max_element(dp.begin(), dp.end());
        return res;
    }
};