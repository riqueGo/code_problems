#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::queue;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        queue<Node*> sources;
        Node* mapping[101];
        bool visited[101];

        Node* sourceNode;
        Node* cloneNode;

        sources.push(node);
        while(!sources.empty()) {
            sourceNode = sources.front();
            sources.pop();

            if(visited[sourceNode->val]) continue;
            visited[sourceNode->val] = true;

            if(!mapping[sourceNode->val]) {
                mapping[sourceNode->val] = new Node(sourceNode->val);
            }
            cloneNode = mapping[sourceNode->val];

            for(Node* neighbor : sourceNode->neighbors) {
                if(!mapping[neighbor->val]) {
                    mapping[neighbor->val] = new Node(neighbor->val);
                }
                cloneNode->neighbors.push_back(mapping[neighbor->val]);
                sources.push(neighbor);
            }

        }
        return mapping[1];
    }
};