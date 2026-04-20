class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        auto [diameter, height] = helper(root);
        return diameter;
    }
    std::pair<int, int> helper(TreeNode* root){
        if (root == nullptr){
            return {0, 0};
        }
        auto [diameter_left, height_left]   = helper(root->left);
        auto [diameter_right, height_right] = helper(root->right);

        return {max({diameter_left, diameter_right, height_left + height_right}), 1 + max(height_left, height_right)} ;
    }
};