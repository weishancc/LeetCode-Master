#include <string>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        int record[26] = {}; // Storing the number of occurrence from a-z, where a maps to [0], z to [25]
        for (int i = 0; i < s.length(); i++)
        {
            record[s[i] - 'a']++;
        }

        for (int j = 0; j < t.length(); j++)
        {
            record[t[j] - 'a']--;
        }

        /* Check if there is element larger or equal than one*/
        for (int k = 0; k < 26; k++)
        {
            if (record[k] != 0)
                return false;
        }

        return true;
    }
};