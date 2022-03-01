#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> res;
        res.push_back(0);

        /* For an integer i, when i%2==0, just shift a bit and the number of 1 will not change,
           when i%2==1, add the rightest bit "1" */
        for (int i = 1; i <= n; i++)
        {
            int x = res[i / 2] + (i % 2);
            res.push_back(x);
        }

        return res;
    }
};