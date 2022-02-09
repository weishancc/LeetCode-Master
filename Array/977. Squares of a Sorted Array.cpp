#include <vector>

class Solution
{
public:
    std::vector<int> sortedSquares(std::vector<int> &nums)
    {
        int k = nums.size() - 1; //
        std::vector<int> result(nums.size());

        for (int i = 0, j = nums.size() - 1; i <= j;)
        {
            if (nums[i] * nums[i] < nums[j] * nums[j])
            {
                result[k--] = nums[j] * nums[j];
                j--;
            }
            else
            {
                result[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};