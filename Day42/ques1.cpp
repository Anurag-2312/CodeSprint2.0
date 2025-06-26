#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *build(vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (nodes[i] != "null")
        {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;
        if (i >= nodes.size())
            break;

        if (nodes[i] != "null")
        {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int count(TreeNode *node, bool left)
{
    int depth = 0;
    while (node)
    {
        depth++;
        node = (left ? node->left : node->right);
    }
    return depth;
}

int countnodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = count(root, true);
    int right = count(root, false);
    if (left == right)
    {
        return pow(2, left) - 1;
    }
    return 1 + countnodes(root->left) + countnodes(root->right);
}

vector<string> input(const string &line)
{
    vector<string> result;
    istringstream ss(line);
    string word;
    while (ss >> word)
        result.push_back(word);
    return result;
}

int main()
{
    cout << "Enter tree nodes: ";
    string line;
    getline(cin, line);

    vector<string> nodes = input(line);
    TreeNode *root = build(nodes);

    int total = countnodes(root);
    cout << "Total number of nodes: " << total << endl;

    return 0;
}
