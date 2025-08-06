/*
 * Time Complexity:
 *   - serialize: O(N)
 *     - Performs a level-order traversal, visiting each node once.
 *   - deserialize: O(N)
 *     - Parses each value in the string once and reconstructs the tree level by level.
 *   - N is the number of nodes in the tree.
 *
 * Space Complexity:
 *   - O(N)
 *     - For the queue used in both serialization and deserialization.
 *     - The output string in `serialize` also takes O(N) space.
 */

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>

using std::string;
using std::queue;
using std::to_string;
using std::stoi;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string s = "";
        TreeNode* currNode;

        while(!q.empty()) {
            currNode = q.front();
            q.pop();

            if(!currNode) {
                s += "n ";
                continue;
            } 

            s += to_string(currNode->val) + ' ';
            q.push(currNode->left);
            q.push(currNode->right);
        }
        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data == "n") return nullptr;

        int l = 0, r = 0, number;
        string numberStr = "";

        while(r < data.size() && data[r] != ' ') r++;

        numberStr = data.substr(l, r-l);
        number = stoi(numberStr);

        r++;
        l=r;

        TreeNode* root = new TreeNode(number);
        TreeNode* currNode;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            currNode = q.front();
            q.pop();

            while(r < data.size() && data[r] != ' ') r++;

            numberStr = data.substr(l, r-l);
            if(numberStr != "n") {
                number = stoi(numberStr);
                TreeNode* left = new TreeNode(number);
                currNode->left = left;
                q.push(left);
            }

            r++;
            l=r;

            while(r < data.size() && data[r] != ' ') r++;

            numberStr = data.substr(l, r-l);
            if(numberStr != "n") {
                number = stoi(numberStr);
                TreeNode* right = new TreeNode(number);
                currNode->right = right;
                q.push(right);
            }

            r++;
            l=r;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));