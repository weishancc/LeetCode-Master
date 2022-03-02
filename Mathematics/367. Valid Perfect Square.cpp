class Solution
{
public:
    /* The difference between perfect square numbers is arithmetic progression, thus, if num is
       a perfect square number, num=1+3+5+7+.. */
    bool isPerfectSquare(int num)
    {
        int subNum = 1;

        while (num > 0)
        {
            num -= subNum;
            subNum += 2;
        }

        return num == 0;
    }
};