#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    int longestPalindromeSubseq(std::string s)
    {
        std::vector<std::vector<int>> dp(s.length(), std::vector<int>(s.length(), 0)); // dp[i][j] is the longest palindromic subsequence's length in s[i:j]

        /* Initialization: when i==j -> len=1 */
        for (int i = 0; i < s.length(); i++)
            dp[i][i] = 1;

        /* Fill dp table */
        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s.length(); j++) // j iterates from i+1 because we've considered case i==j above
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][s.length() - 1];
    }
};