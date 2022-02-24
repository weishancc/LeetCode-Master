#include <vector>
#include <algorithm>

class Solution
{
public:
    int findLength(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        /* dp[i][j] is the maximum length of a subarray that appears in A[0:i-1] and B[0:j-1] */
        std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));

        int res = 0; // Record the maximum length
        for (int i = 1; i <= nums1.size(); i++)
        {
            for (int j = 1; j <= nums2.size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                res = std::max(res, dp[i][j]);
            }
        }

        return res;
    }
};