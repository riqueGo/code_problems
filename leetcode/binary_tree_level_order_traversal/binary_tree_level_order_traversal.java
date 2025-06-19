package binary_tree_level_order_traversal;

import java.util.ArrayList;
import java.util.List;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> levelOrder(TreeNode root) {
        traverse(root, 0);
        return ans;
    }

    private void traverse(TreeNode root, int level) {
        if(root == null) return;
        if(ans.size() == level) {
            List<Integer> tmp = new ArrayList<>();
            tmp.add(root.val);
            ans.add(tmp);
        } else {
            ans.get(level).add(root.val);
        }

        level++;
        traverse(root.left, level);
        traverse(root.right, level);
    }
}
