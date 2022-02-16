#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_set<int> res_set;
        std::unordered_set<int> nums_set(nums1.begin(), nums1.end());

        for (int num : nums2)
        {
            if (nums_set.find(num) != nums_set.end()) // If didn't find, nums_set will return a iterator points to the position of last element
                res_set.insert(num);
        }

        return std::vector<int>(res_set.begin(), res_set.end());
    }
};