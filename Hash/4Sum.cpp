#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            /* Remove the duplicat element */
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            for (int j = i + 1; j < nums.size(); j++)
            {
                /* Remove the duplicat element */
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;

                int left = j + 1;
                int right = nums.size() - 1;

                while (right > left)
                {
                    // (nums[i]] + nums[j] + nums[left] + nums[right] > target) will overflow !!
                    if (nums[i] + nums[j] > target - (nums[left] + nums[right]))
                        right--;
                    else if (nums[i] + nums[j] < target - (nums[left] + nums[right]))
                        left++;
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        /* Remove the duplicat element */
                        while (right > left && nums[right] == nums[right - 1])
                            right--;
                        while (right > left && nums[left] == nums[left + 1])
                            left++;

                        left++;
                        right--;
                    }
                }
            }
        }

        return res;
    }
};