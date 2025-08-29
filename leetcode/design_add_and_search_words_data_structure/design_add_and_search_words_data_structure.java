package design_add_and_search_words_data_structure;

class WordNode {
    boolean isWord;
    WordNode[] letters;

    WordNode() {
        isWord = false;
        letters = new WordNode[26];
    }
}

class WordDictionary {
    private WordNode root;

    public WordDictionary() {
        root = new WordNode();
    }

    public void addWord(String word) {
        WordNode node = root;
        for (char ch : word.toCharArray()) {
            int pos = ch - 'a';
            if (node.letters[pos] == null) {
                node.letters[pos] = new WordNode();
            }
            node = node.letters[pos];
        }
        node.isWord = true;
    }

    public boolean search(String word) {
        return dfs(word, 0, root);
    }

    private boolean dfs(String word, int idx, WordNode node) {
        if (idx == word.length()) {
            return node.isWord;
        }

        char ch = word.charAt(idx);
        if (ch == '.') {
            for (WordNode next : node.letters) {
                if (next != null && dfs(word, idx + 1, next)) {
                    return true;
                }
            }
            return false;
        }

        int pos = ch - 'a';
        if (node.letters[pos] == null) return false;
        return dfs(word, idx + 1, node.letters[pos]);
    }
}

