/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 1. Use dual pointer (fast/slow) where fast moves 2 steps and slow moves 1 at a time.
   If there's a ring, fast will definitely meet slow in the ring because it chased slow pointer
   with 1 step closer.

   2. Then, where will they meet in the ring? --> mathematics
   https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.md
   */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            /* If two pointers meet in the ring, find where they meet; else return NULL */
            if (slow == fast)
            {
                /* In the sutuation of n=1, x equals to z, which means z moves the same
                   step w/ x and they meet in the entrance of the ring; In the sutuation of n>1,
                   fast pointer just moves more rounds and still meet slow pointer in the entrance.*/
                ListNode *index1 = fast;
                ListNode *index2 = head;

                while (fast != head)
                {
                    head = head->next;
                    fast = fast->next;
                }
                return fast; // Return the entrance of the ring
            }
        }
        return nullptr;
    }
};