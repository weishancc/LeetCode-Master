#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        /* Count the frequency */
        std::unordered_map<int, int> map;
        for (int num : nums)
            map[num]++;

        /* Sort by the frequence using priority queue */
        std::priority_queue<std::pair<int, int>> pque;
        for (auto [a, b] : map)
            pque.push({b, a});

        /* Find top K element by traversaling the min heap.
           Because the min heap pop the min element first, the res should be reversed if problem needed */
        std::vector<int> res;
        while (k)
        {
            res.push_back(pque.top().second);
            pque.pop();
            k--;
        }

        return res;
    }
};

// class Solution
// {
// public:
//     std::vector<int> topKFrequent(std::vector<int> &nums, int k)
//     {
//         /* Count the frequency */
//         std::unordered_map<int, int> map;
//         for (int num : nums)
//             map[num]++;

//         /* Sort by the frequence using priority queue */
//         std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pque;

//         /* Construct the min heap */
//         for (std::unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
//         {
//             pque.push({it->second, it->first}); // first is the element and second is the frequency in map

//             /* Make the size of heap equals to k */
//             if (pque.size() > k)
//                 pque.pop();
//         }

//         /* Find top K element by traversaling the min heap.
//            Because the min heap pop the min element first, the res should be reversed if problem needed */
//         std::vector<int> res;
//         while (!pque.empty())
//         {
//             res.push_back(pque.top().second); // second is the element and first is the frequency in pque
//             pque.pop();
//         }

//         return res;
//     }
// };