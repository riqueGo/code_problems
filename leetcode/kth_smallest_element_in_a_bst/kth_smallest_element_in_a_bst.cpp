/*
Problem:
    Find the kth smallest element in a Binary Search Tree (BST).

Approach:
    - Perform an inorder traversal (Left → Node → Right).
    - Inorder traversal of BST gives values in sorted order.
    - Decrement k as we visit nodes.
    - When k reaches 0, the current node is the kth smallest.

Time Complexity:
    - O(H + k), where H is the height of the tree
        * In the worst case (unbalanced BST), H = O(n) → O(n)
        * In the best/average case (balanced BST), H = O(log n) → O(log n + k)
    - Because we stop once we find the kth element, we don’t always traverse the full tree.

Space Complexity:
    - O(H), recursion stack depth (height of tree)
        * O(n) in worst case (skewed tree)
        * O(log n) in balanced tree


Iterative Inorder Traversal (using stack):

Approach:
    - Use a stack to simulate recursion.
    - Push all left children until reaching the leftmost node.
    - Pop from stack (smallest element), decrement k.
    - If k == 0, return that node’s value.
    - Move to the right child and repeat.

Time Complexity:
    - O(H + k), same as recursive version
    - Because we only traverse until kth element.

Space Complexity:
    - O(H), stack size for tree height
*/

#include <stack>

using std::stack;

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
    int ans = -1;

    void dfs(TreeNode* root, int& k) {
        if(root == nullptr || ans >= 0) return;
        dfs(root->left, k);
        k--;
        if(k == 0) ans = root->val;
        dfs(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }

    int iterativeKthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Go as left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            k--;

            if (k == 0) return curr->val;

            curr = curr->right;
        }

        return -1; // should never reach here if input is valid
    }
};