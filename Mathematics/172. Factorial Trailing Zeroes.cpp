class Solution
{
public:
    /* The number of "5" is the number of trailing 0 in n! because 0 comes from 2*5,
    and the number of "2" is more than the number of "5" */
    int trailingZeroes(int n)
    {
        int res = 0;

        while (n)
        {
            res += (n / 5);
            n /= 5;
        }
        return res;
    }
};