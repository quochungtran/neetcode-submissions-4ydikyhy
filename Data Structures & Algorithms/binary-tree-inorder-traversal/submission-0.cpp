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
    vector<int> inorderTraversal(TreeNode* root) {
        // left -> root -> right
        // have function buildListFromTree(TreeNode* root, vector<int>& result)
        vector<int> result;
        buildListFromTree(root, result);
        return result;
                // 4 2 5 1 
    }

    void buildListFromTree(TreeNode* root, vector<int>& result){
        if (root != nullptr){
            buildListFromTree(root->left, result);
            result.push_back(root->val);
            buildListFromTree(root->right, result);
        }
    }
};