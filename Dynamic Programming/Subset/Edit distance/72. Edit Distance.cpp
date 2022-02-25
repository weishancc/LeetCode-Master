#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    int minDistance(std::string word1, std::string word2)
    {
        std::vector<std::vector<int>> dp(word1.length() + 1, std::vector<int>(word2.length() + 1, 0)); // dp[i][j] is the minimum number of operations required to convert word1[0:i-1] to word2[0:j-1]

        /* Initialization: minDistance(word1, "") = len(word1) */
        for (int i = 0; i <= word1.length(); i++)
            dp[i][0] = i;

        /* Initialization: minDistance(word2, "") = len(word2) */
        for (int j = 0; j <= word2.length(); j++)
            dp[0][j] = j;

        /* Fill dp table */
        for (int i = 1; i <= word1.length(); i++)
        {
            for (int j = 1; j <= word2.length(); j++)
            {
                /* If word1[i - 1] == word2[j - 1], no operations needed */
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                /* If word1[i - 1] != word2[j - 1], three operations are considered:
                (1) Delete a word from word1 -> dp[i][j] = dp[i-1][j] + 1;
                (2) Delete a word from word2 (Insert a word to word1) -> dp[i][j] = dp[i][j-1] + 1;
                (3) Replace a word in word1 -> dp[i][j] = dp[i-1][j-1] + 1; */
                else
                    dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }

        return dp[word1.length()][word2.length()];
    }
};