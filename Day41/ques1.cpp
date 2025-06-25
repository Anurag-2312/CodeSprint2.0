#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

TreeNode *build(vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return NULL;

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

int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    string line;
    getline(cin, line);
    istringstream ss(line);
    vector<string> nodes;
    string val;

    while (ss >> val)
        nodes.push_back(val);

    TreeNode *root = build(nodes);
    cout << height(root) << endl;

    return 0;
}
