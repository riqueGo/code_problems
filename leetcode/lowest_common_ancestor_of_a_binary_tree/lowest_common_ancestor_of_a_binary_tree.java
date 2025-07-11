package lowest_common_ancestor_of_a_binary_tree;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private TreeNode ans;
    private TreeNode p;
    private TreeNode q;

    private boolean dfs(TreeNode root) {
        if(root == null) return false;

        boolean left = dfs(root.left);
        if(ans != null) return true;
        boolean right = dfs(root.right);
        boolean rootIsTarget = root.val == p.val || root.val == q.val;

        if(
            (left && right) ||
            (rootIsTarget && (left || right))
        ) {
            ans = root;
            return true;
        } 
        
        return left || right || rootIsTarget;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        this.p = p;
        this.q = q;

        boolean left = dfs(root.left);
        if(ans != null) return ans;
        else if(left) return root;
        dfs(root.right);
        
        return ans != null ? ans : root;
    }
}