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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){
            const auto curr1 = q1.front();
            const auto curr2 = q2.front();

            q1.pop();
            q2.pop();

            if (curr1 == nullptr && curr2 == nullptr){
                continue;
            }

            if ((curr1 == nullptr && curr2 != nullptr) || (curr1 != nullptr && curr2 == nullptr) || (curr1->val != curr2->val)){
                return false;
            }

            q1.push(curr1->left);
            q1.push(curr1->right);
            q2.push(curr2->left);
            q2.push(curr2->right);
        }
        return q1.empty() && q2.empty();
    }
};
