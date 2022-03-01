#include <bits/stdc++.h>

class Solution
{
public:
    /* e.g.,  000101 = 5
       ~num = 111010
       mask = 111000
       ~num ^ mask = 000010
    */
    int findComplement(int num)
    {
        uint32_t mask = ~0;
        while (num & mask)
            mask = mask << 1;

        return ~num ^ mask;
    }
};