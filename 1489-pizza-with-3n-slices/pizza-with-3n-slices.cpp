class Solution {
public:
    struct Node {
        int value;
        Node* left;
        Node* right;
        bool deleted;

        Node(int v)
            : value(v), left(nullptr), right(nullptr), deleted(false) {}
    };

    struct Compare {
        bool operator()(Node* a, Node* b) const {
            return a->value < b->value; // max heap
        }
    };

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();

        vector<Node*> nodes;
        nodes.reserve(n);

        for (int x : slices) {
            nodes.push_back(new Node(x));
        }

        // Circular doubly linked list
        for (int i = 0; i < n; i++) {
            nodes[i]->left = nodes[(i - 1 + n) % n];
            nodes[i]->right = nodes[(i + 1) % n];
        }

        priority_queue<Node*, vector<Node*>, Compare> pq;

        for (auto node : nodes) {
            pq.push(node);
        }

        int total = 0;
        int remainingSlices = n / 3;

        while (remainingSlices) {
            Node* bestNode = pq.top();
            pq.pop();

            if (bestNode->deleted) continue;

            remainingSlices--;
            total += bestNode->value;

            // Delete left and right nodes
            bestNode->left->left->right = bestNode;
            bestNode->right->right->left = bestNode;

            bestNode->left->deleted = true;
            bestNode->right->deleted = true;

            // Trade-in value
            bestNode->value =
                bestNode->left->value +
                bestNode->right->value -
                bestNode->value;

            bestNode->left = bestNode->left->left;
            bestNode->right = bestNode->right->right;

            pq.push(bestNode);
        }

        return total;
    }
};