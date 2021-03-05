#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef pair<int, int> pii;

int maze[101][101];
bool visited[101][101];
int dist[101][101];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int N, M;

bool valid(int x, int y){ return x >= 1 && y >= 1 && x <= N && y <= M; }

void bfs(pii loc)
{
    queue<pii> q;
    q.push(loc);
    visited[loc.F][loc.S] = true;
    dist[loc.F][loc.S] = 1; 
    while(!q.empty())
    {
        pii from = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int tox = from.F + dx[i];
            int toy = from.S + dy[i];
            if(valid(tox, toy) && maze[tox][toy] && !visited[tox][toy])
            {
                q.push({tox, toy});
                visited[tox][toy] = true;
                dist[tox][toy] = dist[from.F][from.S] + 1;
            }
        }
    }
    cout << dist[N][M];
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            scanf("%1d", &maze[i][j]);
        }
    }
    bfs({1, 1});
}