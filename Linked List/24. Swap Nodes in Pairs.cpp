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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;

        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *tmp = cur->next;
            ListNode *tmp2 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp2;

            cur = cur->next->next; // Then move two shift
        }
        return dummy->next;
    }
};