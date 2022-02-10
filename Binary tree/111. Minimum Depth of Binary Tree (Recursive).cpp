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
    int getMinDepth(TreeNode *node)
    {
        if (node == nullptr)
            return 0;

        int leftMax = getMinDepth(node->left);
        int rightMax = getMinDepth(node->right);

        /* If left hand is null and right hand isn't null*/
        if (node->left == nullptr && node->right != nullptr)
            return 1 + rightMax;

        /* If rigjht hand is null and left hand isn't null*/
        if (node->right == nullptr && node->left != nullptr)
            return 1 + leftMax;

        return 1 + std::min(leftMax, rightMax);
    }

public:
    int minDepth(TreeNode *root)
    {
        return getMinDepth(root);
    }
};