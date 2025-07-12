/*
 * Time Complexity: O(H)
 *   - H is the height of the tree.
 *   - Each recursive call moves down one level of the tree.
 *
 * Space Complexity: O(H)
 *   - Due to the recursion stack.
 *   - In the worst case (skewed tree), H = N.
 */

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int pValue;
    int qValue;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root->val == p->val || root->val == q->val) return root;

        pValue = p->val;
        qValue = q->val;

        TreeNode* l = lcaHelper(root->left);
        TreeNode* r = lcaHelper(root->right);

        if(l != nullptr && r != nullptr) return root;
        else if(l != nullptr) return l;
        else return r;
    }

    TreeNode* lcaHelper(TreeNode* root) {
        if(root == nullptr || root->val == pValue || root->val == qValue) return root;

        TreeNode* l = lcaHelper(root->left);
        TreeNode* r = lcaHelper(root->right);

        if(l != nullptr && r != nullptr) return root;
        else if(l != nullptr) return l;
        else return r;
    }
};