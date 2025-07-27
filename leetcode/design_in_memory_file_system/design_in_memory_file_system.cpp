/*
 * Time Complexity:
 *   - ls, mkdir, addContentToFile, readContentFromFile: O(L + K log K)
 *     - L is the number of parts in the path (depth of the file/directory).
 *     - K is the number of files/directories in the current directory (for ls sorting).
 *     - Each path operation traverses at most L nodes.
 *
 * Space Complexity: O(N)
 *   - N is the total number of files and directories created.
 *   - Space is used for the tree structure and file contents.
 */

#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;
using std::unordered_map;
using std::stringstream;
using std::sort;

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
struct FileNode {
    bool isFile;
    string content;
    unordered_map<string, FileNode*> children;
    FileNode() : isFile(false) {}
};

class FileSystem {
private:
    FileNode* root;

    vector<string> split(const string& s, const char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            if (!token.empty()) {
                tokens.emplace_back(token);
            }
        }
        return tokens;
    }

    FileNode* getFileNode(const string& path) {
        FileNode* currNode = root;
        vector<string> parts = split(path, '/');
        for (const string& part : parts) {
            currNode = currNode->children[part];
        }
        return currNode;
    }

    FileNode* putFileNode(const string& path) {
        FileNode* currNode = root;
        vector<string> parts = split(path, '/');
        for (const string& part : parts) {
            if (currNode->children.find(part) == currNode->children.end()) {
                currNode->children[part] = new FileNode();
            }
            currNode = currNode->children[part];
        }
        return currNode;
    }

public:
    FileSystem() {
        root = new FileNode();
    }

    vector<string> ls(string path) {
        FileNode* currNode = getFileNode(path);
        if(currNode->isFile) {
            return {split(path, '/').back()};
        }

        vector<string> ans;
        for(const auto& child : currNode->children) {
            ans.emplace_back(child.first);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }

    void mkdir(string path) {
        putFileNode(path);
    }

    void addContentToFile(string filePath, string content) {
        FileNode* fileNode = putFileNode(filePath);
        fileNode->isFile = true;
        fileNode->content += content;
    }

    string readContentFromFile(string filePath) {
        return getFileNode(filePath)->content;
    }
};