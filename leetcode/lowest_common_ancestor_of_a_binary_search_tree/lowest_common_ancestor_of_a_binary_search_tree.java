package lowest_common_ancestor_of_a_binary_search_tree;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private int targetP;
    private int targetQ;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || root.val == p.val || root.val == q.val) return root;

        targetP = p.val;
        targetQ = q.val;

        TreeNode l = lcaHelper(root.left);
        TreeNode r = lcaHelper(root.right);

        if(l != null && r != null) return root;
        else if(l != null) return l;
        else return r;
    }

    public TreeNode lcaHelper(TreeNode root) {
        if(root == null || root.val == targetP || root.val == targetQ) return root;

        TreeNode l = lcaHelper(root.left);
        TreeNode r = lcaHelper(root.right);

        if(l != null && r != null) return root;
        else if(l != null) return l;
        else return r;
    }

    public static void main(String[] args) {
        TreeNode tr = new TreeNode(
            6,
            new TreeNode(
                2,
                new TreeNode(0),
                new TreeNode(
                    4,
                    new TreeNode(3),
                    new TreeNode(5)
                )
            ),
            new TreeNode(
                8,
                new TreeNode(7),
                new TreeNode(9)
            )
        );
        new Solution().lowestCommonAncestor(tr, new TreeNode(2), new TreeNode(4));
    }
}
