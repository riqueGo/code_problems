package serialize_and_deserialize_binary_tree;

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return "n";

        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode curr = q.poll();

            if (curr == null) {
                sb.append("n ");
                continue;
            }

            sb.append(curr.val).append(" ");
            q.add(curr.left);
            q.add(curr.right);
        }

        sb.setLength(sb.length() - 1);
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data == null || data.equals("n")) return null;

        String[] nodes = data.split(" ");
        int i = 0;

        TreeNode root = new TreeNode(Integer.parseInt(nodes[i++]));
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode curr = q.poll();

            if (i < nodes.length && !nodes[i].equals("n")) {
                curr.left = new TreeNode(Integer.parseInt(nodes[i]));
                q.add(curr.left);
            }
            i++;

            if (i < nodes.length && !nodes[i].equals("n")) {
                curr.right = new TreeNode(Integer.parseInt(nodes[i]));
                q.add(curr.right);
            }
            i++;
        }

        return root;
    }
}

