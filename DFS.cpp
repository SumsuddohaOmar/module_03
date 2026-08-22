#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool visited[105];
void DFS(int src)
{
    visited[src] = true;
    cout << src << " ";
    for (int child : adj_list[src])
    {
        if (!visited[child])
        {
            visited[child] = true;
            DFS(child);
        }
    }
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
    memset(visited, false, sizeof(visited));
    DFS(0);
    return 0;
}