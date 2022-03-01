#include <cstdint>

class Solution
{
public:
    /* Retrieve the last bit of n, and put in the leftest side just like reversing decimal number! */
    uint32_t reverseBits(uint32_t n)
    {
        int ret = 0;

        for (int i = 0; i < 32; i++)
        {
            ret = ret << 1;
            ret = ret | (n & 1); // (n & 1) is the last bit of n
            n = n >> 1;
        }

        return ret;
    }
};