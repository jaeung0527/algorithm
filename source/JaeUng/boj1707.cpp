#include <bits/stdc++.h>

#define R 0
#define B 1

using namespace std;

vector<int> graph[20001];
bool color[20001];
bool visited[20001];

bool bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int from = q.front(); q.pop();
        for(int to : graph[from])
        {
            if(!visited[to])
            {
                if(color[from] == color[to])
                    color[to] = !color[to];
                q.push(to);
                visited[to] = true;
            }
            else if(visited[to] && color[to] == color[from])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;
    while(K--)
    {
        int V, E;
        cin >> V >> E;
        while(E--)
        {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);    
        }
        bool ans = true;
        for(int i = 1; i <= V; i++)
        {
            if(visited[i] == false && !bfs(i))
            {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n"); 
        memset(visited, false, sizeof(visited));
        memset(visited, false, sizeof(color));
        for(int i = 1; i <= V; i++) graph[i].clear();
    }
}