#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool visited[105];
vector<int> nodes_per_component;
int DFS(int src)
{
    int nodes = 1;
    for (int child : adj_list[src])
    {
        if (!visited[child])
        {
            visited[child] = true;
            nodes += DFS(child);
        }
    }
    return nodes;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            nodes_per_component.push_back(DFS(i));
        }
    }
    sort(nodes_per_component.begin(), nodes_per_component.end());
    for (int x : nodes_per_component)
        cout << x << " ";
    return 0;
}