#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool visited[105];
void DFS(int src)
{
    visited[src] = true;
    for(int child : adj_list[src])
    {
        if(!visited[child])
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
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int component = 0;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            component++;
            DFS(i);
        }
    }
    cout << component;
    return 0;
}