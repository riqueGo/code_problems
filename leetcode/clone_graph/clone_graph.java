package clone_graph;

import java.util.LinkedList;
import java.util.Queue;

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if(node == null) return null;

        Queue<Node> sources = new LinkedList<>();
        Node sourceNode = null;
        Node cloneNode = null;
        Node[] mapping = new Node[101];
        boolean[] visited = new boolean[101];

        sources.add(node);
        while(!sources.isEmpty()) {
            sourceNode = sources.poll();

            if(visited[sourceNode.val]) continue;

            visited[sourceNode.val] = true;

            if(mapping[sourceNode.val] == null) {
                mapping[sourceNode.val] = new Node(sourceNode.val);
            }
            cloneNode = mapping[sourceNode.val];

            for(Node neighbor : sourceNode.neighbors) {
                if(mapping[neighbor.val] == null) {
                    mapping[neighbor.val] = new Node(neighbor.val);
                }
                cloneNode.neighbors.add(mapping[neighbor.val]);
                sources.add(neighbor);
            }
        }

        return mapping[1];
    }
}
