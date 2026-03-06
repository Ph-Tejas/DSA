/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Serialize using preorder traversal
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    void preorder(TreeNode* node, string &s) {
        if (!node) return;
        s += to_string(node->val) + ",";
        preorder(node->left, s);
        preorder(node->right, s);
    }

    // Deserialize
    TreeNode* deserialize(string data) {
        vector<int> values;
        string temp = "";

        for (char c : data) {
            if (c == ',') {
                values.push_back(stoi(temp));
                temp = "";
            } else {
                temp += c;
            }
        }

        int index = 0;
        return build(values, index, INT_MIN, INT_MAX);
    }

    TreeNode* build(vector<int>& values, int& index, int minVal, int maxVal) {
        if (index >= values.size()) return NULL;

        int val = values[index];
        if (val < minVal || val > maxVal) return NULL;

        TreeNode* root = new TreeNode(val);
        index++;

        root->left = build(values, index, minVal, val);
        root->right = build(values, index, val, maxVal);

        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;