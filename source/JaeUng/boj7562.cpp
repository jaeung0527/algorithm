#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef pair<int, int> pii;

const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int l;

bool valid(int x, int y){ return x >= 0 && y >= 0 && x < l && y < l; }
void bfs(pii start, pii end)
{
    queue<pii> q;
    int dist[300][300] = {0, };
    bool visited[300][300] = {false, };

    q.push(start);
    dist[start.F][start.S] = 0;
    visited[start.F][start.S] = true;

    while(!q.empty())
    {
        pii from = q.front(); q.pop();
        for(int i = 0; i < 8; i++)
        {
            int tox = from.F + dx[i];
            int toy = from.S + dy[i];
            if(valid(tox, toy) && !visited[tox][toy])
            {
                q.push({tox, toy});
                dist[tox][toy] = dist[from.F][from.S] + 1;
                visited[tox][toy] = true;
            }
        }
    }
    cout << dist[end.F][end.S] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--)
    {
        cin >> l;
        pii start, end;
        cin >> start.F >> start.S;
        cin >> end.F >> end.S;
        bfs(start, end);   
    }
}