#include <vector>
#include <bits/stdc++.h>
#include <deque>

/* Monotonic Queue: O(n) */
class Solution
{
private:
    class MyQueue
    {
    public:
        std::deque<int> que; // Use deque to implement monotonic queue

        void pop(int value)
        {
            if (!que.empty() && value == que.front())
            {
                que.pop_front();
            }
        }

        /* If push value is larger than front value, pop up from the back until the push value is smaller than front value.
           As the result, the queue is monotonic. */
        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }

        /* The max value is just the front value of queue */
        int front()
        {
            return que.front();
        }
    };

public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
    {
        MyQueue que;
        std::vector<int> res;

        for (int i = 0; i < k; i++)
            que.push(nums[i]);
        res.push_back(que.front()); // Record the max element among first k elements to ans

        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]);       // Slide the window to remove the first element
            que.push(nums[i]);          // Push the last element before sliding the window
            res.push_back(que.front()); // Record the max element to ans
        }
        return res;
    }
};

// /* Brute Force will TLE: O(nk) */
// class Solution
// {
// public:
//     std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k)
//     {
//         int l = 0;         // left pointer of window
//         int r = l + k - 1; // right pointer of window
//         int max;
//         std::vector<int> res;

//         while (r < nums.size())
//         {
//             max = INT_MIN;
//             for (int num : std::vector<int>{nums.begin() + l, nums.begin() + r + 1})
//             {
//                 if (num > max)
//                     max = num;
//             }

//             res.push_back(max); // Add the max to ans

//             l++;
//             r++;
//         }

//         return res;
//     }
// };