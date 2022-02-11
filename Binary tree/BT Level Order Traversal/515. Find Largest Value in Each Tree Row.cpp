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
    std::vector<int> largestValues(TreeNode *root)
    {
        std::queue<TreeNode *> qu;
        std::vector<int> ret;

        if (root != nullptr)
            qu.push(root);

        while (!qu.empty())
        {
            int size = qu.size();
            std::vector<int> vec;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = qu.front();
                qu.pop();
                vec.push_back(node->val);
                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);
            }

            ret.push_back(*std::max_element(vec.begin(), vec.end())); // Add the max element in each level
            vec.clear();
        }
        return ret;
    }
};