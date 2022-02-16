#include <unordered_set>

class Solution
{
private:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }

public:
    bool isHappy(int n)
    {
        std::unordered_set<int> set;
        while (1)
        {
            int sum = getSum(n);
            if (sum == 1) // Return true if find happy number
                return true;
            else if (set.find(sum) != set.end()) // Enter infinite loop so 1 will not be found
                return false;
            else
            {
                set.insert(sum);
                n = sum;
            }
        }
    }
};