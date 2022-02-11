/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <vector>
#include <queue>

class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(Node *root)
    {
        std::queue<Node *> qu;
        std::vector<std::vector<int>> ret;

        if (root != nullptr)
            qu.push(root);

        while (!qu.empty())
        {
            int size = qu.size();
            std::vector<int> vec;

            for (int i = 0; i < size; i++)
            {
                Node *node = qu.front();
                qu.pop();
                vec.push_back(node->val);

                for (int j = 0; j < (node->children).size(); j++)
                {
                    if (node->children[j])
                        qu.push(node->children[j]);
                }
            }
            ret.push_back(vec);
        }
        return ret;
    }
};