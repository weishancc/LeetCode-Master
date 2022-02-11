/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        std::queue<TreeNode *> qu;
        int ret = 0;

        if (root != nullptr)
            qu.push(root);
        else
            return 0;

        while (!qu.empty())
        {
            int size = qu.size();
            ret++; // Record the depth

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = qu.front();
                qu.pop();
                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }
        }
        return ret;
    }
};