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
#include <algorithm>
#include <bits/stdc++.h>

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
    int getMinimumDifference(TreeNode *root)
    {
        traversal(root);

        /* Determine min value between the vector */
        int res = INT_MAX;
        for (int i = 1; i < vec.size(); i++)
            res = std::min(vec[i] - vec[i - 1], res);

        return res;
    }
};

// /*--------------------------------------------------------------------------------*/
// /* Version2: Directly compute the diff when traveral -> use *cur and *pre pointer */
// /*--------------------------------------------------------------------------------*/
// class Solution
// {
//     int res = INT_MAX;
//     TreeNode *pre;

//     void traversal(TreeNode *cur)
//     {
//         if (cur == nullptr)
//             return;

//         traversal(cur->left);
//         if (pre != nullptr)
//             res = std::min(res, cur->val - pre->val);
//         pre = cur;
//         traversal(cur->right);
//     }

// public:
//     int getMinimumDifference(TreeNode *root)
//     {
//         traversal(root);
//         return res;
//     }
// };