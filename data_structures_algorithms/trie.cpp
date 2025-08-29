#include <bits/stdc++.h>
using namespace std;

/*
 Trie Data Structure:
 ---------------------
 - A Trie (prefix tree) is a tree-like data structure used for storing strings efficiently,
   especially for prefix-based queries.
 - Each node represents a character of a string.
 - Common operations:
     1. insert(word): Insert a word into the trie.
     2. search(word): Check if a word exists in the trie.
     3. startsWith(prefix): Check if there is any word that starts with the given prefix.

 Node Structure:
 ---------------
 - Each node contains:
     * An array/map of child nodes (for each character).
     * A flag indicating if the node represents the end of a word.

 Complexity:
 -----------
 - Insert: O(L), where L = length of word
 - Search: O(L)
 - Space: O(N * A) where N = number of words, A = alphabet size (26 for lowercase letters)
*/

class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];

    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isWord = true;
    }

    // Search a word in the trie
    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << boolalpha; // Print true/false instead of 1/0
    cout << "Search 'apple': " << trie.search("apple") << "\n";   // true
    cout << "Search 'app': " << trie.search("app") << "\n";       // true
    cout << "Search 'appl': " << trie.search("appl") << "\n";     // false
    cout << "Starts with 'ap': " << trie.startsWith("ap") << "\n"; // true
    cout << "Starts with 'bat': " << trie.startsWith("bat") << "\n"; // true
    cout << "Starts with 'cat': " << trie.startsWith("cat") << "\n"; // false

    return 0;
}

/*
 Output:
 -------
 Search 'apple': true
 Search 'app': true
 Search 'appl': false
 Starts with 'ap': true
 Starts with 'bat': true
 Starts with 'cat': false
*/

