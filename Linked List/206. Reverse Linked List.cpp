/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *next;
        ListNode *cur = head;
        ListNode *prev = nullptr;

        while (cur)
        {
            next = cur->next; // 0) Record current node to tmp so that we can move to next node
            cur->next = prev; // 1) Reverse the link!!
            prev = cur;       // 2) Update the new head node
            cur = next;       // 3) Last, move to next node
        }
        return prev;
    }
};