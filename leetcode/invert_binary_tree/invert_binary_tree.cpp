/*
 * Time Complexity: O(N)
 *   - Each node is visited once.
 *
 * Space Complexity: O(H)
 *   - H is the height of the tree (recursion stack).
 */

#include<iostream>
#include<queue>

using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void printTopDown(TreeNode* root) {
        if(root == nullptr) return;
        queue<TreeNode*> treeNodeQueue;
        treeNodeQueue.push(root);

        TreeNode *curr;
        while(!treeNodeQueue.empty()){
            curr = treeNodeQueue.front();
            treeNodeQueue.pop();

            std::cout << curr->val << " ";

            if(curr->left != nullptr) {
                treeNodeQueue.push(curr->left);
            }

            if(curr->right != nullptr) {
                treeNodeQueue.push(curr->right);
            }
        }
        std::cout << std::endl;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        queue<TreeNode*> treeNodeQueue;
        treeNodeQueue.push(root);

        TreeNode *curr, *tmp;
        while(!treeNodeQueue.empty()){
            curr = treeNodeQueue.front();
            treeNodeQueue.pop();

            tmp = curr->left;
            curr->left = curr->right;
            curr->right = tmp;

            if(curr->left != nullptr) {
                treeNodeQueue.push(curr->left);
            }

            if(curr->right != nullptr) {
                treeNodeQueue.push(curr->right);
            }
        }
        return root;
    }
};

int main() {
    TreeNode root (
        4,
        new TreeNode(
            2,
            new TreeNode(1),
            new TreeNode(6)
        ),
        new TreeNode(
            7,
            new TreeNode(3),
            new TreeNode(9)
        )
    );

    root.printTopDown(&root);

    Solution s;
    s.invertTree(&root);

    root.printTopDown(&root);
}