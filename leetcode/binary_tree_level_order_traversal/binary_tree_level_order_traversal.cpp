/*
 * Time Complexity: O(N)
 *   - N is the number of nodes in the tree.
 *   - Each node is visited once.
 *
 * Space Complexity: O(N)
 *   - For the answer vector and recursion stack (in the worst case).
 */

#include <vector>

using std::vector;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        traverse(root, ans, 0);
        return ans;
    }

    void traverse(TreeNode* root, vector<vector<int>>& ans, int level) {
        if(root == nullptr) return;
        if(ans.size() == level) {
            ans.push_back({root->val});
        } else {
            ans[level].push_back(root->val);
        }

        level++;
        traverse(root->left, ans, level);
        traverse(root->right, ans, level);
    }
};