#include <bits/stdc++.h>
using namespace std;
int n, e;
char grid[105][105];
bool visited[105][105];
int level[105][105];
pair<int, int> parents[105][105];
vector<pair<int, int>> child_dif = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= e)
        return false;
    if(grid[i][j] != '.')
        return false;
    return true;
}

void BFS(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int par_i = parent.first;
        int par_j = parent.second;
        cout << par_i << " " << par_j << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + child_dif[i].first;
            int cj = par_j + child_dif[i].second;
            if (valid(ci, cj) && !visited[ci][cj])
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
                parents[ci][cj] = parent;
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < e; j++)
            cin >> grid[i][j];

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parents, -1, sizeof(parents));
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    cout << "All the existing nodes in the graph\n";
    BFS(si, sj);
    cout << "Shortest distance to a destination node: " << level[di][dj] << endl;
    cout << "Shortest path to a destination node:\n";
    pair<int, int> destination = {di, dj};
    while (destination.first != -1 && destination.second != -1)
    {
        cout << destination.first << " " << destination.second << endl;
        destination = parents[destination.first][destination.second];
    }

    return 0;
}