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
    ListNode() : val(0), next() {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        /* Shift fast pointer by (n+1) */
        while (n--)
            fast = fast->next;
        fast = fast->next;

        /* Shift both slow and fast pointer until fast faces NULL */
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        /* Remove the node */
        slow->next = slow->next->next;

        return dummy->next;
    }
};