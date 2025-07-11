/*
 * Time Complexity: O(N), where N is the number of nodes in the tree.
 *   - Each node is visited once by the dfs traversal.
 * Space Complexity: O(H), where H is the height of the tree.
 *   - Due to the recursion stack. In the worst case (skewed tree), H = N, so space is O(N).
 *   - In a balanced tree, H = log N.
 */

#include <cstddef>
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool dfs(TreeNode*& root, TreeNode*& p, TreeNode*& q, TreeNode*& ans) {
        if(root == nullptr) return false;

        bool left = dfs(root->left, p, q, ans);
        if(ans != nullptr) return true;
        bool right = dfs(root->right, p, q, ans);
        bool isRootTarget = root == p || root == q;

        if(
            (left && right) ||
            (isRootTarget && (left || right))
        ) {
            ans = root;
            return true;
        }

        return isRootTarget || left || right;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        bool left = dfs(root->left, p, q, ans);
        if(ans != nullptr) return ans;
        else if(left && (root == p || root == q)) return root;

        bool right = dfs(root->right, p, q, ans);
        return ans != nullptr ? ans : root;
    }
};