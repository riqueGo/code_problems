/*
 * Time Complexity: O(N)
 *   - N is the number of nodes in the tree.
 *   - Each node is visited once.
 *
 * Space Complexity: O(H)
 *   - H is the height of the tree (recursion stack).
 *   - In the worst case (skewed tree), H = N.
 */

#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* root, long min, long max) {
        return root == nullptr || (root->val > min && root->val < max && dfs(root->left, min, root->val) && dfs(root->right, root->val, max));
    }
};