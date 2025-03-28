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
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        queue<Node*> q;        
        q.push(node);
        unordered_map<Node*, Node*> hm;
        hm[node] = new Node(node->val);

        while (!q.empty())
        {
            Node* temp = q.front();
            q.pop();

            for (auto nd : temp->neighbors)
            {
                if (hm.find(nd) == hm.end())
                {
                    hm[nd] = new Node(nd->val);
                    q.push(nd);
                }
                hm[temp]->neighbors.push_back(hm[nd]);
            }

        }

        return hm[node];
    }
};