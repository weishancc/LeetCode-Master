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
    int maxCount; // Max Count
    int count;    // Current count
    TreeNode *pre = nullptr;
    std::vector<int> res;

public:
    void traversal(TreeNode *root)
    {
        if (root == nullptr)
            return;

        traversal(root->left);

        if (pre == nullptr) // The first node
            count = 1;
        else if (pre->val == root->val) // Current value is the same w/ the prev one
            count++;
        else // Current value isn't the same w/ the prev one
            count = 1;
        pre = root;

        if (count == maxCount)
            res.push_back(root->val);

        if (count > maxCount)
        {
            maxCount = count;
            res.clear();
            res.push_back(root->val);
        }
        traversal(root->right);
    }

    std::vector<int> findMode(TreeNode *root)
    {
        maxCount = 0;
        count = 0;
        traversal(root);
        return res;
    }
};