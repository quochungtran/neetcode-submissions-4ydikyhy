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
    bool isBalanced(TreeNode* root) {
        // return isBalanaced(root->left) or isBalance(root->right) or abs(height(root->left) - height(root->right)) > 1

        auto [isBalance, height] = dfs(root);
        return isBalance;
    }

    pair<bool, int> dfs(TreeNode* root){
        if (root == nullptr){
            return {true, 0};
        }
        auto [isBalanceLeft, height_left] = dfs(root->left);
        auto [isBalanceRight, height_right] = dfs(root->right);

        return {(isBalanceLeft && isBalanceRight && abs(height_left - height_right) <= 1), 
                max(height_left, height_right) + 1};
    }

};
