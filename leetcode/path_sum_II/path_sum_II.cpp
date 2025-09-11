/*
 * Time Complexity: O(N)
 *   - Each node is visited once in the DFS traversal.
 *
 * Space Complexity: O(H)
 *   - H is the height of the tree (O(log N) for balanced tree, O(N) for skewed tree).
 *   - Due to recursion stack and the path vector.
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
private:
    vector<vector<int>> ans;

    void dfs(TreeNode* root, vector<int>& currNodes, int currSum, int targetSum) {
        currNodes.push_back(root->val);
        currSum += root->val;

        if(root->left == nullptr && root->right == nullptr) {
            if(currSum == targetSum) {
                ans.push_back(currNodes);
            }
        } else {
            if(root->left) dfs(root->left, currNodes, currSum, targetSum);
            if(root->right) dfs(root->right, currNodes, currSum, targetSum);
        }

        currNodes.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return ans;
        vector<int> currNodes;
        dfs(root, currNodes, 0, targetSum);
        return ans;
    }
};
