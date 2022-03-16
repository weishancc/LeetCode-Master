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
    TreeNode *traversal(std::vector<int> &inorder, std::vector<int> &postorder)
    {
        /* (1) If size of inderer is 0 -> it's null  */
        if (inorder.size() == 0)
            return nullptr;

        /* (2) Find the middle node to split left and right hand tree, which actually is the last element in postorder */
        TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);

        /* If size of postorderer is 1 -> it's leaf*/
        if (postorder.size() == 1)
            return root;

        /* (3) Find split node in inorder*/
        int index;
        for (index = 0; index < inorder.size(); index++)
        {
            if (inorder[index] == root->val)
                break;
        }

        /* (4) Start to split inorder vector */
        std::vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        std::vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        /* (5) Start to split postorder vector */
        postorder.resize(postorder.size() - 1);
        std::vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        std::vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        /* (6) Recur to traversal */
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

public:
    TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        return traversal(inorder, postorder);
    }
};