package invert_binary_tree;

import java.util.LinkedList;
import java.util.Queue;

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
    public TreeNode invertTree(TreeNode root) {
        Queue<TreeNode> treeNodeQueue = new LinkedList<>();
        treeNodeQueue.add(root);

        TreeNode curr, tmp;
        while(!treeNodeQueue.isEmpty()) {
            curr = treeNodeQueue.poll();

            tmp = curr.left;
            curr.left = curr.right;
            curr.right = tmp;

            if(curr.left != null) {
                treeNodeQueue.add(curr.left);
            }

            if(curr.right != null) {
                treeNodeQueue.add(curr.right);
            }
        }
        return root;
    }

    public static void main(String[] args) {
        //[4,2,7,1,3,6,9]
        TreeNode root = new TreeNode(
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

        root.printTopDown(root);
        new Solution().invertTree(root);
        root.printTopDown(root);
    }
}