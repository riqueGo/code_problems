package diameter_of_binary_tree;

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
    private int treeLength = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        fn(root);
        return treeLength;
    }

    private int fn(TreeNode root) {
        if(root == null) return 0;
        int left = fn(root.left);
        int right = fn(root.right);
        treeLength = Math.max(treeLength, left+right);
        return Math.max(left,right)+1;
    }
}
