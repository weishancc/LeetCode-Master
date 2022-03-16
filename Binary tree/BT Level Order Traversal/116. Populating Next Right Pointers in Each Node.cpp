/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <vector>
#include <queue>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        std::queue<Node *> qu;

        if (root != nullptr)
            qu.push(root);

        while (!qu.empty())
        {
            int size = qu.size();
            Node *node;
            Node *pre; // Previous node of *node variable

            for (int i = 0; i < size; i++)
            {
                if (i == 0)
                {
                    node = qu.front();
                    qu.pop();
                    pre = node;
                }
                else
                {
                    node = qu.front();
                    qu.pop();
                    pre->next = node;
                    pre = node;
                }

                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }
            node->next = nullptr; // The last node in each level points to nullptr
        }

        return root;
    }
};