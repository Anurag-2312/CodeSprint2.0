#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &DFS)
{
    vis[node] = 1;
    DFS.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis, DFS);
    }
}

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n);
    cout << "Enter adjacency list:\n";
    for (int i = 0; i < n; ++i)
    {
        int m;
        cout << "Number of adjacent nodes for " << i << ": ";
        cin >> m;
        cout << "Enter " << m << " connected nodes: ";
        for (int j = 0; j < m; ++j)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    vector<int> vis(n, 0);
    vector<int> DFS;
    dfs(0, adj, vis, DFS);

    cout << "DFS Traversal Order: ";
    for (int node : DFS)
        cout << node << " ";
    cout << endl;

    return 0;
}
