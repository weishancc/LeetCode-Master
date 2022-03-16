#include <vector>
#include <algorithm>

/* O(n): Boyer-Moore Majority Vote Algorithm */
class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int cnt = 0;
        int majority = nums[0];

        for (int num : nums)
        {
            if (cnt == 0)
            {
                cnt++;
                majority = num;
            }
            else if (num == majority)
                cnt++;
            else
                cnt--;
        }

        return majority;
    }
};

// /* O(nlog(n)) */
// class Solution
// {
// public:
//     int majorityElement(std::vector<int> &nums)
//     {
//         std::sort(nums.begin(), nums.end());

//         return nums[nums.size() / 2];
//     }
// };