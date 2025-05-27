//CF link https://codeforces.com/contest/590/problem/C
#include <bits/stdc++.h>
using namespace std;


const int N = 1010;
const int INF = 1e9;


int n, m;
vector<string> grid;
vector<vector<vector<int>>> dist;


int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#');
}


void multi_source_bfs(vector<pair<int, int>> &sources, int source_type)
{
    deque<pair<int, int>> dq;


    for (auto &source : sources)
    {
        dist[source_type][source.first][source.second] = 0;
        dq.push_back(source);
    }


    while (!dq.empty())
    {
        auto [x, y] = dq.front();
        dq.pop_front();


        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];


            if (is_valid(nx, ny))
            {
                int cost = (grid[nx][ny] == '.' ? 1 : 0);
                if (dist[source_type][nx][ny] > dist[source_type][x][y] + cost)
                {
                    dist[source_type][nx][ny] = dist[source_type][x][y] + cost;
                    if (cost == 0)
                    {
                        dq.push_front({nx, ny});
                    }
                    else
                    {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
    }
}


void solve()
{
    cin >> n >> m;
    grid.resize(n);
    dist.assign(4, vector<vector<int>>(n, vector<int>(m, INF)));


    vector<pair<int, int>> sources[4];


    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] >= '1' && grid[i][j] <= '3')
            {
                sources[grid[i][j] - '0'].push_back({i, j});
            }
        }
    }


    for (int i = 1; i <= 3; i++)
    {
        multi_source_bfs(sources[i], i);
    }


    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != '#')
            {
                if (dist[1][i][j] == INF || dist[2][i][j] == INF || dist[3][i][j] == INF)
                    continue;


                long long path_cost = dist[1][i][j] + dist[2][i][j] + dist[3][i][j];
                if (grid[i][j] == '.')
                    path_cost -= 2;
                ans = min(ans, path_cost);
            }
        }
    }


    if (ans == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}