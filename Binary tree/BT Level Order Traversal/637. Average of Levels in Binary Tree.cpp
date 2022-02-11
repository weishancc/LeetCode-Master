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
    std::vector<double> averageOfLevels(TreeNode *root)
    {
        std::queue<TreeNode *> qu;
        std::vector<double> ret;

        if (root != nullptr)
            qu.push(root);

        while (!qu.empty())
        {
            int size = qu.size();
            double sum = 0;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = qu.front();
                qu.pop();
                sum += node->val; // Sum every node in each level

                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }
            ret.push_back(sum / size);
        }
        return ret;
    }
};