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

class Solution {
    unordered_map<Node*, Node*> seen;
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        if (seen.count(node)) {
            return seen[node];
        }

        Node *cloned = new Node(node->val, {});
        seen[node] = cloned;

        for (auto nei : node->neighbors) {
            cloned->neighbors.push_back(cloneGraph(nei));
        }
        
        return seen[node];
    }  
};