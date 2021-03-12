#include <bits/stdc++.h>

using namespace std;

int N, M;
bool ans;

vector<int> graph[2000];
bool visited[2000];

void dfs(int from, int depth)
{
    if(depth == 5) 
    {
        ans = true;
        return;
    }

    for(int to : graph[from])
    {
        if(!visited[to] &&!ans)
        {
            visited[to] = true;
            dfs(to, depth + 1);
            visited[to] = false;    
        }
    }
}

void solve()
{
    for(int i = 0; i < N; i++)
    {
        if(!ans)
        {
            visited[i] = true;
            dfs(i, 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0, from, to; i < M; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    solve();
    cout << ans;
}