#include <vector>
#include <algorithm>

class Solution
{
public:
    int minMoves2(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end()); // Sort the vector first to find median, O(nlogn)
        int median = nums[nums.size() / 2];
        int res = 0;

        for (int num : nums)
        {
            res += abs(median - num);
        }

        return res;
    }
};