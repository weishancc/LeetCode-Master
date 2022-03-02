#include <vector>
#include <cmath>
#include <algorithm>

class Solution
{
public:
    /* Sieve of Eratosthenes */
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
            return 0;

        std::vector<bool> vec(n, true);
        vec[0] = false;
        vec[1] = false;

        for (int i = 2; i <= sqrt(n); i++) // If n isn't prime -> n=a*b, a<=b -> a<=sqrt(n)
        {
            if (!vec[i])
                continue;

            for (int j = i * i; j < n; j += i) // Mark the multiples of i as "false"
                vec[j] = false;
        }

        int res = count(vec.begin(), vec.end(), true);
        return res;
    }
};