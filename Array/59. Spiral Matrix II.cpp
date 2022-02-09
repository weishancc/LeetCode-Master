#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));

        int startX = 0;   // Starting position-X of every circle round
        int startY = 0;   // Starting position-Y of every circle round
        int count = 1;    // Counter to fill
        int loop = n / 2; // How many circle rounds to fill
        int offset = 1;   // The number of filled block, need to be deleted every circle round
        int i;
        int j;

        while (loop--)
        {

            /* In the following we begin to fill all the four directions: left2right, up2down,
               right2left, and down2up. Left hand is closed and right hand is open. */
            for (j = startY; j < startY + n - offset; j++)
            {
                res[startX][j] = count++;
            }

            for (i = startX; i < startX + n - offset; i++)
            {
                res[i][j] = count++;
            }

            for (; j > startY; j--)
            {
                res[i][j] = count++;
            }

            for (; i > startX; i--)
            {
                res[i][j] = count++;
            }

            /* Starting position added by 1 when every cycle round*/
            startX++;
            startY++;

            /* Update offset */
            offset += 2;
        }

        /* Fill the center if n is odd*/
        if (n % 2 != 0)
            res[n / 2][n / 2] = count;
        return res;
    }
};