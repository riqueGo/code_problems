/*
Time Complexity:
- addWord: O(L)
- search:
    Best Case: O(L)
    Worst Case: O(26^d), where d = number of '.' characters
Space Complexity: O(N * L) for storing all words
*/

#include <string>

using std::string;

class WordNode {
public:
    bool isWord;
    WordNode* letters[26];

    WordNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) letters[i] = nullptr;
    }
};

class WordDictionary {
private:
    WordNode* root;

    bool dfs(const string& word, int idx, WordNode* node) {
        if (idx == word.size()) return node->isWord;

        char ch = word[idx];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->letters[i] && dfs(word, idx + 1, node->letters[i]))
                    return true;
            }
            return false;
        }

        int pos = ch - 'a';
        if (!node->letters[pos]) return false;
        return dfs(word, idx + 1, node->letters[pos]);
    }

public:
    WordDictionary() {
        root = new WordNode();
    }

    void addWord(string word) {
        WordNode* node = root;
        for (char ch : word) {
            int pos = ch - 'a';
            if (!node->letters[pos]) node->letters[pos] = new WordNode();
            node = node->letters[pos];
        }
        node->isWord = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};
