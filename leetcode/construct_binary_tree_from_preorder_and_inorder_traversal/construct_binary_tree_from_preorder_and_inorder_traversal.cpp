/*
 * Time Complexity: O(N)
 *   - Each node is processed once.
 *   - The index lookup in the unordered_map is O(1), done N times.
 *
 * Space Complexity: O(N)
 *   - Recursion stack takes O(H), where H is height of tree → worst case O(N).
 *   - Additional O(N) space for the hashmap.
 */

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

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
    unordered_map<int, int> inorderIndexMap;

    TreeNode* build(
        vector<int>& preorder, int& preIndex,
        int inStart, int inEnd
    ) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderIndexMap[rootVal];

        root->left = build(preorder, preIndex, inStart, inIndex - 1);
        root->right = build(preorder, preIndex, inIndex + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return build(preorder, preIndex, 0, inorder.size() - 1);
    }
};

int main() {
    // Example usage:
    Solution solution;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode* root = solution.buildTree(preorder, inorder);
    
    // Clean up the allocated memory for the tree nodes if necessary.
    return 0;
}