class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int z = x ^ y;
        int res = 0;

        while (z)
        {
            if ((z & 1) == 1)
                res++;
            z = z >> 1;
        }

        return res;
    }
};