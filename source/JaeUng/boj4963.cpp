#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef pair<int, int> pii;

int w, h;
int graph[51][51];
bool visited[51][51];
vector<int> ans;

const int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool valid(int x, int y){ return x >= 1 && y >= 1 && x <= h && y <= w ; }
void bfs(pii v)
{
    queue<pii> q;
    q.push(v);
    visited[v.F][v.S] = true;

    while(!q.empty())
    {
        pii from = q.front(); q.pop();
        for(int i = 0; i < 8; i++)
        {
            int tox = from.F + dx[i];
            int toy = from.S + dy[i];
            if(valid(tox, toy) && !visited[tox][toy] && graph[tox][toy])
            {
                q.push({tox, toy});
                visited[tox][toy] = true;
            }
        }
    }
}

int main()
{   
    int ans = 0;
    while(true)
    {
        scanf("%d %d", &w, &h); 
        if(w == 0 && h == 0) break;

        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                scanf("%d", &graph[i][j]);
            }
        }    
        for(int i = 1; i <= h; i++)
        {
            for(int j = 0; j <= w; j++)
            {
                if(!visited[i][j] && graph[i][j])
                {
                    bfs({i, j});
                    ans += 1;
                }
            }
        }
        cout << ans << '\n';
        ans = 0;
        memset(visited, false, sizeof(visited));
    }
}   