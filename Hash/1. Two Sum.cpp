#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(target - nums[i]) != map.end())
                return {map.find(target - nums[i])->second, i}; // (map.find(target - nums[i])->second) is the value of map[key], which equals to map[target-nums[i]]

            map[nums[i]] = i;
        }

        return {};
    }
};