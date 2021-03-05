#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    cout << v << ' ';
    while(!q.empty())
    {
        int from = q.front(); q.pop();
        for(int to : graph[from])
        {
            if(!visited[to])
            {
                q.push(to);
                visited[to] = true;
                cout << to << ' ';
            }
        }
    }
}

void dfs(int v)
{
    visited[v] = true;
    cout << v << ' ';
    for(int to : graph[v])
    {
        if(!visited[to])
        {
            visited[to] = true;
            dfs(to);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    while(M--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(V); cout << '\n';
    memset(visited, false, sizeof(visited));
    bfs(V);
}