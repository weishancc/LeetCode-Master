#include <string>

class Solution
{
public:
    std::string addStrings(std::string num1, std::string num2)
    {
        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        std::string res = "";

        while (carry > 0 || i >= 0 || j >= 0)
        {
            int x = i < 0 ? 0 : num1.at(i) - '0'; // The rightest digit in num1
            int y = j < 0 ? 0 : num2.at(j) - '0'; // The rightest digit in num2

            res = std::to_string((x + y + carry) % 10) + res;
            carry = (x + y + carry) / 10;

            i--;
            j--;
        }

        return res;
    }
};