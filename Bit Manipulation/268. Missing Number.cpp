#include <vector>

class Solution
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        int res = 0;

        /* Using the advantage of (x^x=0), just xor every element and the index */
        for (int i = 0; i < nums.size(); i++)
            res = res ^ i ^ nums[i];

        return res ^ nums.size(); // res^n
    }
};