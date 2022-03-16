class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;

        // /* or using popcount to count the nubmer of "1" */
        // return n>0 && __builtin_popcount(n) == 1;
    }
};