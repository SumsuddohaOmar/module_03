#include <bits/stdc++.h>
using namespace std;
int n, m;
char building_map[1005][1005];
bool visited[1005][1005];
vector<pair<int, int>> walk = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    if (building_map[i][j] != '.')
        return false;
    return true;
}

void walking_on_floor(int floor_i, int floor_j)
{
    visited[floor_i][floor_j] = true;
    for (int i = 0; i < 4; i++)
    {
        int next_i = floor_i + walk[i].first;
        int next_j = floor_j + walk[i].second;
        if (valid(next_i,next_j) && !visited[next_i][next_j])
            walking_on_floor(next_i, next_j);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> building_map[i][j];
        }
    }
    int room = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && building_map[i][j] == '.')
            {
                room++;
                walking_on_floor(i, j);
            }
        }
    }
    cout << room;
    return 0;
}