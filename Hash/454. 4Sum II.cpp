#include <vector>
#include <unordered_map>

class Solution
{
public:
    int fourSumCount(std::vector<int> &nums1, std::vector<int> &nums2, std::vector<int> &nums3, std::vector<int> &nums4)
    {
        std::unordered_map<int, int> map; // key: a+b, value: number of occurrence of a+b

        for (int a : nums1)
        {
            for (int b : nums2)
            {
                map[a + b]++;
            }
        }

        int count = 0; // The number of case (a+b+c+d=0)
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                /* If (0-(c+d)) is found, retrieve the nubmer of occrence of (a+b) to count */
                if (map.find(0 - (c + d)) != map.end())
                    count += map[0 - (c + d)];
            }
        }

        return count;
    }
};