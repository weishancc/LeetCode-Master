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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        /* If didn't find deleted node */
        if (root == nullptr)
            return root;

        /* If find deleted node */
        if (root->val == key)
        {
            // Case1: leaf node
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }

            // Case2: left is null and right isn't null
            if (root->left == nullptr && root->right != nullptr)
            {
                auto retNode = root->right;
                delete root;
                return retNode;
            }

            // Case3: left isn't null and right is null
            if (root->left != nullptr && root->right == nullptr)
            {
                auto retNode = root->left;
                delete root;
                return retNode;
            }

            // Case4: neither left and right are null
            if (root->left != nullptr && root->right != nullptr)
            {
                /* Find the leftest node in right subtree */
                TreeNode *cur = root->right;
                while (cur->left != nullptr)
                    cur = cur->left;

                cur->left = root->left;
                TreeNode *tmp = root; // Keep the root because we'll update the new one
                root = root->right;
                delete tmp;

                return root;
            }
        }

        if (key > root->val)
            root->right = deleteNode(root->right, key);
        if (key < root->val)
            root->left = deleteNode(root->left, key);

        return root;
    }
};