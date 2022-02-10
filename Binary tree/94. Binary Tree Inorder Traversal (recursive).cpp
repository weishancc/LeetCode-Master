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
    std::vector<int> res;

    std::vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);

        return res;
    }
};

// /* Preorder*/
// class Solution
// {
// public:
//     std::vector<int> res;

//     std::vector<int> preorderTraversal(TreeNode *root)
//     {
//         if (root == nullptr)
//             return {};

//         res.push_back(root->val);
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);

//         return res;
//     }
// };

// /* Postorder*/
// class Solution
// {
// public:
//     std::vector<int> res;

//     std::vector<int> postorderTraversal(TreeNode *root)
//     {
//         if (root == nullptr)
//             return {};

//         postorderTraversal(root->left);
//         postorderTraversal(root->right);
//         res.push_back(root->val);

//         return res;
//     }
// };