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
    TreeNode *traversal(std::vector<int> &nums, int left, int right)
    {
        /* We usually take the middle element in list so that it becomes naturally a height-balanced BST */

        if (left > right)
            return nullptr;
            
        int middle = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[middle]);
        root->left = traversal(nums, left, middle - 1);
        root->right = traversal(nums, middle + 1, right);

        return root;
    }

public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        return traversal(nums, 0, nums.size() - 1);
    }
};