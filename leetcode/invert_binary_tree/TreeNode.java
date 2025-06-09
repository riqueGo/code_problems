package invert_binary_tree;

import java.util.LinkedList;
import java.util.Queue;

public class TreeNode {
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

    public void printTopDown(TreeNode root) {
        if(root == null) return;
        Queue<TreeNode> treeNodeQueue = new LinkedList<>();
        treeNodeQueue.add(root);

        TreeNode curr;
        while (!treeNodeQueue.isEmpty()) {
            curr = treeNodeQueue.poll();

            System.out.print(curr.val + " ");
            if(curr.left != null){
                treeNodeQueue.add(curr.left);
            }

            if(curr.right != null) {
                treeNodeQueue.add(curr.right);
            }
        }
        System.out.println();
    }
}
