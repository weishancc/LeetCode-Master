#include <string>

class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        int record[26] = {}; // Storing the number of occurrence from a-z, e.g., record[0] is the number of occurrence  of 'a'

        for (int i = 0; i < magazine.length(); i++)
            record[magazine[i] - 'a']++;

        /* Iterate ransomNote, if character 'c' in magazine,
           (1) If the number of occurence is zero, return false because ransomdeNote used unseen character'
           (2) else, decrease num of occurence by 1 and iterate next character' */
        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (record[ransomNote[i] - 'a'] == 0)
                return false;
            else
                record[ransomNote[i] - 'a']--;
        }

        return true;
    }
};