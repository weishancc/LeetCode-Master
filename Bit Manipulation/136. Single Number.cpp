#include <vector>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int res = 0;

        for (int num : nums)
            res = res ^ num;

        return res;
    }
};