package path_sum_II;

import java.util.ArrayList;
import java.util.List;

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
    private List<List<Integer>> ans = new ArrayList<>();

    private void dfs(TreeNode root, List<Integer> currNodes, int currSum, int targetSum) {
        currNodes.add(root.val);
        currSum += root.val;

        if (root.left == null && root.right == null) {
            if (currSum == targetSum) {
                ans.add(new ArrayList<>(currNodes));
            }
        } else {
            if (root.left != null) dfs(root.left, currNodes, currSum, targetSum);
            if (root.right != null) dfs(root.right, currNodes, currSum, targetSum);
        }

        currNodes.remove(currNodes.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        if (root == null) return ans;
        dfs(root, new ArrayList<>(), 0, targetSum);
        return ans;
    }
}
