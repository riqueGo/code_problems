package implement_trie;

class Node {
    Node[] childs;
    boolean isEnd;

    Node() {
        childs = new Node[26];
        isEnd = false;
    }
}

class Trie {
    Node head;

    public Trie() {
        head = new Node();
    }
    
    public void insert(String word) {
        Node currNode = head;
        for(char ch : word.toCharArray()) {
            int idx = ch-'a';
            if(currNode.childs[idx] == null) currNode.childs[idx] = new Node();
            currNode = currNode.childs[idx];
        }
        currNode.isEnd = true;
    }
    
    public boolean search(String word) {
        Node currNode = head;
        for(char ch : word.toCharArray()) {
            int idx = ch-'a';
            if(currNode.childs[idx] == null) return false;
            currNode = currNode.childs[idx];
        }
        return currNode.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        Node currNode = head;
        for(char ch : prefix.toCharArray()) {
            int idx = ch-'a';
            if(currNode.childs[idx] == null) return false;
            currNode = currNode.childs[idx];
        }
        return true;
        
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
