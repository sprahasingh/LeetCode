// Title: Minimum Depth of Binary Tree
            // Difficulty: Easy
            // Language: C++
            // Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left
 (left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};
