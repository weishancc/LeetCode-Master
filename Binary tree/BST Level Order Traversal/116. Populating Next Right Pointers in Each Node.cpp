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
            Node *node;
            Node *nodePre; // Previous node of *node variable

            int size = qu.size();
            for (int i = 0; i < size; i++)
            {
                if (i == 0)
                {
                    nodePre = qu.front();
                    qu.pop();
                    node = nodePre;
                }
                else
                {
                    node = qu.front();
                    qu.pop();
                    nodePre->next = node;
                    nodePre = nodePre->next;
                }

                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }
            nodePre->next = nullptr; // The last node in each level points to nullptr
        }

        return root;
    }
};