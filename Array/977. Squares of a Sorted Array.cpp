#include <vector>

class Solution
{
public:
    std::vector<int> sortedSquares(std::vector<int> &nums)
    {
        std::vector<int> res(nums.size(), 0);
        int k = nums.size() - 1;

        for (int i = 0, j = nums.size() - 1; i <= j;)
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
            {
                res[k--] = nums[i] * nums[i];
                i++;
            }
            else
            {
                res[k--] = nums[j] * nums[j];
                j--;
            }
        }

        return res;
    }
};