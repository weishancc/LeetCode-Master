#include <string>

class Solution
{
public:
    std::string convertToBase7(int num)
    {
        bool isNeg = num < 0;
        num = abs(num);
        std::string res = "";

        /* Use do-while here can deal with the case "0" */
        do
        {
            res = std::to_string(num % 7) + res;
            num /= 7;
        } while (num > 0);

        return isNeg ? res.insert(0, "-") : res; // If num is negative, insert a negative sign to res
    }
};