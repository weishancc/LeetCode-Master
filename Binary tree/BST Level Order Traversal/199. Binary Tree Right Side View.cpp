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
    std::vector<int> rightSideView(TreeNode *root)
    {
        std::queue<TreeNode *> qu;
        std::vector<int> ret;

        if (root != nullptr)
            qu.push(root);
            
        while (!qu.empty())
        {
            int size = qu.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = qu.front();
                qu.pop();

                /* Push last element of every level to answer */
                if (i == (size - 1))
                    ret.push_back(node->val);

                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }
        }
        return ret;
    }
};