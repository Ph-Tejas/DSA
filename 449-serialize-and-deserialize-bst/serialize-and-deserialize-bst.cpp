#include <cstddef>
#include <string>
#include <list>
#include <sstream>

using namespace std;


class Codec {
public:

    void serializeHelper(TreeNode* root, string& res) {
        if (!root) {
            res += "#,"; // Empty node
            return;
        }
        res += to_string(root->val) + ",";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }

    string serialize(TreeNode* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }

    TreeNode* deserializeHelper(list<string>& nodes) {
        string val = nodes.front();
        nodes.pop_front();

        if (val == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> nodes;
        string str;
        stringstream ss(data);
        while (getline(ss, str, ',')) {
            nodes.push_back(str);
        }
        return deserializeHelper(nodes);
    }
};