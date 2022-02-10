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

#include<algorithm>
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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root)
    {
        std::queue<TreeNode *> qu;
        std::vector<std::vector<int>> ret;

        /* Push root to queue first */
        if (root != nullptr)
            qu.push(root);

        /* Iterate every level. When queue is empty, traversal is done */
        while (!qu.empty())
        {
            int size = qu.size();
            std::vector<int> vec;

            /* Iterate every node in each level */
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

            ret.push_back(vec);
        }

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};