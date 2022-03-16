/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <utility>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;

        // Calculate the len of two lists
        while (curA != nullptr)
        {
            lenA++;
            curA = curA->next;
        }

        while (curB != nullptr)
        {
            lenB++;
            curB = curB->next;
        }

        /* Make listA longer than listB*/
        curA = headA;
        curB = headB;
        if (lenB > lenA)
        {
            std::swap(lenA, lenB);
            std::swap(curA, curB);
        }

        /* Align two lists */
        int lenDiff = lenA - lenB;
        while (lenDiff--)
            curA = curA->next;

        /* Iterate two lists to find the intersection*/
        while (curA != nullptr)
        {
            if (curA == curB)
                return curA;
            else
            {
                curA = curA->next;
                curB = curB->next;
            }
        }

        return nullptr;
    }
};