#include <vector>
#include <string>

class Solution
{
public:
    int isSubsequence(std::string s, std::string t)
    {
        /* dp[i][j] is the longest common subsequence between s[0:i-1] and t[0:j-1] */
        std::vector<std::vector<int>> dp(s.length() + 1, std::vector<int>(t.length() + 1, 0));

        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 1; j <= t.length(); j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    /* If s[i - 1] != t[j - 1], we delete t[j-1] so that we comapre s[i-1] w/ t[j-2]
                       -> dp[i][j] = dp[i][j-1] */

                    dp[i][j] = dp[i][j - 1];
            }
        }

        return dp[s.length()][t.length()] == s.length() ? true : false;
    }
};