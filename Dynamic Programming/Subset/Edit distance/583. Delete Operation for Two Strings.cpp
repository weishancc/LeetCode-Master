#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    int minDistance(std::string word1, std::string word2)
    {
        std::vector<std::vector<int>> dp(word1.length() + 1, std::vector<int>(word2.length() + 1, 0)); // dp[i][j] is the longest common subsequence between word1[0:i-1] and word2[0:j-1]

        for (int i = 1; i <= word1.length(); i++)
        {
            for (int j = 1; j <= word2.length(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        /* Except for the longest common substring, the other words shoulbe be deleted and each delete operation
           takes one step. Thus, we need to delete (len(word1)-len(lcs)) + (len(word2)-len(lcs)) times. */
        return word1.length() + word2.length() - dp[word1.length()][word2.length()] * 2;
    }
};