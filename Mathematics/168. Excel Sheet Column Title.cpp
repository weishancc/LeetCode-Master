#include <string>

class Solution
{
public:
    std::string convertToTitle(int columnNumber)
    {
        std::string res = "";

        while (columnNumber > 0)
        {
            columnNumber--;

            res = (char)(columnNumber % 26 + 'A') + res;
            columnNumber /= 26;
        }

        return res;
    }
};