#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *fun(vector<int> &nums, int left, int right)
{
    if (left > right)
        return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = fun(nums, left, mid - 1);
    root->right = fun(nums, mid + 1, right);

    return root;
}

void print(TreeNode *root)
{
    if (!root)
    {
        cout << "null\n";
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    vector<string> res;

    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (cur)
        {
            res.push_back(to_string(cur->val));
            q.push(cur->left);
            q.push(cur->right);
        }
        else
        {
            res.push_back("null");
        }
    }
    while (!res.empty() && res.back() == "null")
        res.pop_back();

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Enter sorted array elements: ";
    string line;
    getline(cin, line);

    vector<int> nums;
    istringstream ss(line);
    int x;
    while (ss >> x)
    {
        nums.push_back(x);
    }

    TreeNode *root = fun(nums, 0, nums.size() - 1);

    cout << "Level order of height-balanced BST: ";
    print(root);

    return 0;
}
