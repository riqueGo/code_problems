/*
 * Time Complexity:
 *   - insert: O(L), L is the length of the word.
 *   - search: O(L)
 *   - startsWith: O(L)
 *
 * Space Complexity: O(N * L)
 *   - N is the number of words, L is the average length.
 */

#include <string>

using std::string;

class Node {
public:
    Node* childs[26];
    bool isEnd;

    Node() {
        isEnd = false;
        for (auto &a : childs) a = nullptr;
    }    
};

class Trie {
private:
    Node* head;

public:
    Trie() {
        head = new Node();
    }
    
    void insert(string word) {
        Node* currNode = head;
        for(char ch : word) {
            int idx = ch-'a';
            if(!currNode->childs[idx]) currNode->childs[idx] = new Node();
            currNode = currNode->childs[idx];
        }
        currNode->isEnd = true;
    }
    
    bool search(string word, bool isPrefix = false) {
        Node* currNode = head;
        for(char ch : word) {
            int idx = ch-'a';
            if(!currNode->childs[idx]) return false;
            currNode = currNode->childs[idx];
        }
        return currNode->isEnd || isPrefix;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    // Example usage:
    Trie* trie = new Trie();
    trie->insert("apple");
    trie->insert("app");
    bool searchResult = trie->search("apple"); // returns true
    bool startsWithResult = trie->startsWith("app"); // returns true
    bool searchResult2 = trie->search("app"); // returns false
    delete trie; // Clean up memory
}