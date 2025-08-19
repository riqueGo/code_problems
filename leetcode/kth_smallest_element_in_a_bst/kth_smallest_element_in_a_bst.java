package kth_smallest_element_in_a_bst;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private int ans = -1;
    private int k;

    private void dfs(TreeNode root) {
        if (root == null || ans >= 0) return;

        dfs(root.left);
        k--;
        if (k == 0) {
            ans = root.val;
            return;
        }
        dfs(root.right);
    }

    public int kthSmallest(TreeNode root, int k) {
        this.k = k;
        dfs(root);
        return ans;
    }
}
