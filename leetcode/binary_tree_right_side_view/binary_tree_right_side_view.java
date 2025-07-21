package binary_tree_right_side_view;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if(root == null) return ans;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        int level = 1;
        TreeNode curr;

        while(!q.isEmpty()) {
            curr = q.poll();

            if(curr.left != null) q.add(curr.left);
            if(curr.right != null) q.add(curr.right);

            if(--level == 0) {
                ans.add(curr.val);
                level = q.size();
            }
        }
        return ans;
    }
}
