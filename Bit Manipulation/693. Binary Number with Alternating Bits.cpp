#include <bits/stdc++.h>

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int a = (n ^ (n >> 1)); // If n has alternating bits, 'a' consists of 1

        return (a & ((long)a + 1)) == 0;
    }
};