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

#include <algorithm>

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
    int getHeight(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        /* If it's not height-balanced binary tree, return -1 */
        if (leftHeight == -1)
            return -1;
        if (rightHeight == -1)
            return -1;

        int res = 1 + std::max(leftHeight, rightHeight); // Max depth when current node is the root
        return std::abs(leftHeight - rightHeight) > 1 ? -1 : res;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return getHeight(root) == -1 ? false : true;
    }
};