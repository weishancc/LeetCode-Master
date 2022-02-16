#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());

        /* Three pointers are used, where 'i' pointer iterates nums,
           'left' and 'right' pointer move seperately to let nums[i] + nums[left] + nums[right] = 0 */
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                return res;

            /* Remove the duplicate element */
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] > 0) // 3Sum is too large, move right pointer
                    right--;
                else if (nums[i] + nums[left] + nums[right] < 0) // 3Sum is too small, move left pointer
                    left++;
                else // 3Sum is 0, record the ans and remove duplicate element
                {
                    res.push_back({nums[i], nums[left], nums[right]});

                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;

                    left++;
                    right--;
                }
            }
        }

        return res;
    }
};