#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::string> commonChars(std::vector<std::string> &words)
    {
        int record[26] = {};      // Storing the number of character occurrence of words[0]
        int recordOther[26] = {}; // Storing the number of character occurrence from words[0]..words[size-1]

        for (int i = 0; i < words[0].length(); i++)
            record[words[0][i] - 'a']++;

        for (int i = 1; i < words.size(); i++)
        {
            std::memset(recordOther, 0, 26 * sizeof(int));
            for (int j = 0; j < words[0].length(); j++)
                recordOther[words[i][j] - 'a']++;

            /* The min character occurence is min(record, recordOther) */
            for (int k = 0; k < 26; k++)
                record[k] = std::min(record[k], recordOther[k]);
        }

        /* Calculate number of character occurrence and add them to result*/
        std::vector<std::string> res;
        for (int k = 0; k < 26; k++)
        {
            while (record[k] != 0)
            {
                std::string s(1, k + 'a');
                res.push_back(s);
                record[k]--;
            }
        }

        return res;
    }
};