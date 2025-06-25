#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<string> &nodes)
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

bool mirror(TreeNode *t1, TreeNode *t2)
{
    if (!t1 && !t2)
    {
        return true;
    }
    if (!t1 || !t2 || t1->val != t2->val)
    {
        return false;
    }
    return mirror(t1->left, t2->right) && mirror(t1->right, t2->left);
}

bool symmetric(TreeNode *root)
{
    return mirror(root, root);
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

    TreeNode *root = buildTree(nodes);
    cout << (symmetric(root) ? "true" : "false") << endl;

    return 0;
}
