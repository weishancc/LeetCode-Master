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
    std::vector<int> vec;

    void traversal(TreeNode *root)
    {
        /* Inoderer traversal the tree */
        if (root == nullptr)
            return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        traversal(root);

        /* Verify if the value list is increased successively */
        for (int i = 1; i < vec.size(); i++)
            if (vec[i] <= vec[i - 1])
                return false;

        return true;
    }
};