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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }

    TreeNode* dfs(TreeNode* root){
        if (root == nullptr){
            return nullptr;
        }
        swap(root->left, root->right);
        dfs(root->left);
        dfs(root->right);
        return root;
    }
};
