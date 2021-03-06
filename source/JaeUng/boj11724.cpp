#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans;
vector<int> graph[1001];
bool visited[1001];

void bfs(int v)
{
    queue<int> q;
    visited[v] = true;
    q.push(v);
    while(!q.empty())
    {
        int from = q.front(); q.pop();
        for(int to : graph[from])
        {
            if(!visited[to])
            {
                q.push(to);
                visited[to] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    while(M--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
        {
            ans += 1;
            bfs(i);
        }
    }
    cout << ans;
}