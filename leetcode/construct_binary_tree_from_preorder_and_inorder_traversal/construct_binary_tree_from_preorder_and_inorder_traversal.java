package construct_binary_tree_from_preorder_and_inorder_traversal;

import java.util.Map;
import java.util.HashMap;

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
    private Map<Integer, Integer> inorderIndexMap;
    
    private TreeNode build(
        int[] preorder, int[] inorder,
        int[] preIndex,
        int inStart, int inEnd
    ) {
        if (inStart > inEnd) return null;

        int rootVal = preorder[preIndex[0]++];
        TreeNode root = new TreeNode(rootVal);

        int inIndex = inorderIndexMap.get(rootVal);

        root.left = build(preorder, inorder, preIndex, inStart, inIndex - 1);
        root.right = build(preorder, inorder, preIndex, inIndex + 1, inEnd);

        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        inorderIndexMap = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderIndexMap.put(inorder[i], i);
        }

        int[] preIndex = {0}; // simulate pass-by-reference
        return build(preorder, inorder, preIndex, 0, inorder.length - 1);
    }
}