#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
bool visited[105];
void BFS(int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=true;
    int visit_node = 1;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for(int child:adj_list[parent])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child]=true;
                visit_node++;
            }
        }
    }
    cout << visit_node;
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
    int src;
    cin >> src;
    BFS(src);
    return 0;
}