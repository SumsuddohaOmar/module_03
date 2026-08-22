#include <bits/stdc++.h>
using namespace std;
int n, e;
char grid[105][105];
bool visited[105][105];
vector<pair<int, int>> child_dif = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= e)
        return false;
    if(grid[i][j] != '.')
        return false;
    return true;
}

void DFS(int si, int sj)
{
    visited[si][sj] = true;
    cout << si << " " << sj << endl;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + child_dif[i].first;
        int cj = sj + child_dif[i].second;
        if (valid(ci, cj) && !visited[ci][cj])
            DFS(ci, cj);
    }
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < e; j++)
            cin >> grid[i][j];

    memset(visited, false, sizeof(visited));
    int si, sj;
    cin >> si >> sj;
    DFS(si, sj);
    return 0;
}