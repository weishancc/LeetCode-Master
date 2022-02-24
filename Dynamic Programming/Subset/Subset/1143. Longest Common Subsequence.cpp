#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    int longestCommonSubsequence(std::string nums1, std::string nums2)
    {
        /* dp[i][j] is the longest common subsequence between nums1[0:i-1] and nums2[0:j-1] */
        std::vector<std::vector<int>> dp(nums1.length() + 1, std::vector<int>(nums2.length() + 1, 0));

        for (int i = 1; i <= nums1.length(); i++)
        {
            for (int j = 1; j <= nums2.length(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[nums1.length()][nums2.length()];
    }
};