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
#include <string>

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
    void constructPath(TreeNode *node, std::string path, std::vector<std::string> &paths)
    {
        if (node != nullptr)
        {
            path += std::to_string(node->val);

            /* If leaf nodes, add the current path to answer (which is variable paths) */
            if (node->left == nullptr && node->right == nullptr)
                paths.push_back(path);

            /* If not leaf nodes, continue to traversal */
            else
            {
                path += "->";
                constructPath(node->left, path, paths);
                constructPath(node->right, path, paths);
            }
        }
    }

public:
    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        std::vector<std::string> paths;
        constructPath(root, "", paths);
        return paths;
    }
};