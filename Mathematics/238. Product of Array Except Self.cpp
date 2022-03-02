#include <vector>

class Solution
{
public:
    /* Choose a target i, multiply lhs (nums[:i-1]) and rhs of i (nums[i+1:])is the desired output */
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> res(nums.size());
        res[0] = 1;

        /* LHS */
        for (int i = 1; i < nums.size(); i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }

        /* RHS (Directlly update the multiplied result)*/
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res[i] = res[i] * right;
            right = right * nums[i]; // Update the multiplied result of rhs
        }

        return res;
    }
};