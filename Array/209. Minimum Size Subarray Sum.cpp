#include <vector>

class Solution
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int result = 1e6 ;  // Length of output subarray
        int i = 0;              // Start point of sliding window
        int sum = 0;            // Sum of sliding window
        int subLength = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                subLength = (j - i + 1);
                result = subLength < result ? subLength : result; // Record min result
                sum -= nums[i]; // Sliding start point and narrow the window
                i++;
            }
        }
        return result == 1e6 ? 0 : result;
    }
};