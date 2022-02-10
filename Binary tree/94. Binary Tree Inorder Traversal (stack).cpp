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
#include <stack>

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
    std::stack<TreeNode *> st;

    std::vector<int> inorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
            st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != nullptr)
            {
                st.pop();

                /* Add right node */
                if (node->right)
                    st.push(node->right);

                /* Add center node */
                st.push(node);
                st.push(nullptr); // Mark as NULL because it hasn't been handled

                /* Add left node */
                if (node->left)
                    st.push(node->left);
            }
            else
            {
                st.pop(); // Pop NULL
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};

// /* Preorder*/
// class Solution
// {
// public:
//     std::vector<int> res;
//     std::stack<TreeNode *> st;

//     std::vector<int> preorderTraversal(TreeNode *root)
//     {
//         if (root != nullptr)
//             st.push(root);
//         while (!st.empty())
//         {
//             TreeNode *node = st.top();
//             if (node != nullptr)
//             {
//                 st.pop();

//                 /* Add right node */
//                 if (node->right)
//                     st.push(node->right);

//                 /* Add left node */
//                 if (node->left)
//                     st.push(node->left);

//                 /* Add center node */
//                 st.push(node);
//                 st.push(nullptr); // Mark as NULL because it hasn't been handled
//             }
//             else
//             {
//                 st.pop(); // Pop NULL
//                 node = st.top();
//                 st.pop();
//                 res.push_back(node->val);
//             }
//         }
//         return res;
//     }
// };

// /* Postorder*/
// class Solution
// {
// public:
//     std::vector<int> res;
//     std::stack<TreeNode *> st;

//     std::vector<int> postorderTraversal(TreeNode *root)
//     {
//         if (root != nullptr)
//             st.push(root);
//         while (!st.empty())
//         {
//             TreeNode *node = st.top();
//             if (node != nullptr)
//             {
//                 st.pop();

//                 /* Add center node */
//                 st.push(node);
//                 st.push(nullptr); // Mark as NULL because it hasn't been handled

//                 /* Add right node */
//                 if (node->right)
//                     st.push(node->right);

//                 /* Add left node */
//                 if (node->left)
//                     st.push(node->left);
//             }
//             else
//             {
//                 st.pop(); // Pop NULL
//                 node = st.top();
//                 st.pop();
//                 res.push_back(node->val);
//             }
//         }
//         return res;
//     }
// };