#include <vector>
#include <string>

class Solution
{
public:
    int countSubstrings(std::string s)
    {
        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false)); // dp[i][j] is true if s[i:j] is palindromic substring
        int res = 0;                                                                     // Used to record the number of palindromic substrings

        for (int i = s.size() - 1; i >= 0; i--) // i from bottom to up becasue we determined dp[i][j] by dp[i + 1][j - 1]
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] != s[j])
                    dp[i][j] = false;
                else
                {
                    if (j - i <= 1) // If s[i]==s[j] and s[i],s[j] is the same position or adjencent postition
                    {
                        res++;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1]) // If s[i]==s[j] and distance(s[i],s[j])>1 , just check dp[i+1][j-1] to determine dp[i][j]
                    {
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }

        return res;
    }
};