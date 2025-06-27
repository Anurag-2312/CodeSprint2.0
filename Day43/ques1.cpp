#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<vector<int>> &adj)
{
    vector<int> vis(n, 0);
    vector<int> ans;
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return ans;
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

    vector<int> result = bfs(n, adj);
    cout << "BFS Traversal Order: ";
    for (int node : result)
        cout << node << " ";
    cout << endl;

    return 0;
}
