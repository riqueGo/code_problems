/*
 * Time Complexity: O(N)
 *   - N is the number of nodes in the tree.
 *   - Each node is visited once during the level order traversal.
 *
 * Space Complexity: O(W)
 *   - W is the maximum width of the tree (maximum number of nodes at any level).
 *   - Due to the queue used for level order traversal.
 */

#include <vector>
#include <queue>

using std::vector;
using std::queue;

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
    
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        TreeNode* curr;

        while(!q.empty()) {
            curr = q.front();
            q.pop();
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

            if(--level == 0) {
                ans.push_back(curr->val);
                level = q.size();
            }
        }

        return ans;
    }
};