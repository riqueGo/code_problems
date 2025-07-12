/*
 * Time Complexity: O(N)
 *   - N is the number of nodes in the tree.
 *   - Each node is visited once.
 *
 * Space Complexity: O(H)
 *   - H is the height of the tree (recursion stack).
 *   - In the worst case (skewed tree), H = N.
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
    int diameterOfBinaryTree(TreeNode* root) {
        int treeLength = 0;
        fn(root, treeLength);
        return treeLength;
    }

    int fn(TreeNode* root, int &treeLength) {
        if(root == nullptr) return 0;
        int left = fn(root->left, treeLength);
        int right = fn(root->right, treeLength);
        treeLength = max(treeLength, left+right);
        return max(left,right)+1;
    }
};