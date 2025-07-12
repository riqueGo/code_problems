/*
 * Time Complexity: O(N)
 *   - Each node is visited once in the recursion.
 *
 * Space Complexity: O(H)
 *   - H is the height of the tree (recursion stack).
 *   - In the worst case (skewed tree), H = N, so space is O(N).
 *   - In a balanced tree, H = log N.
 */

#include<algorithm>

using std::max;

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
    bool isBalanced(TreeNode* root) {
        return fn(root) != -1;
    }

    int fn(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = fn(root->left);
        if(left == -1) return -1;
        int right = fn(root->right);
        if(right == -1) return -1;
        if(abs(left-right) > 1) return -1;
        return max(left,right)+1;
    }
};