#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef pair<int, int> pii;

int N;
int town[25][25];
bool visited[25][25];
vector<int> ans;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool valid(int x, int y){ return x >= 0 && y >= 0 && x < N && y < N ; }
int bfs(pii v)
{
    int ret = 0;
    queue<pii> q;
    q.push(v); ret += 1; visited[v.F][v.S] = true;

    while(!q.empty())
    {
        pii from = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
            int tox = from.F + dx[i];
            int toy = from.S + dy[i];
            if(valid(tox, toy) && !visited[tox][toy] && town[tox][toy])
            {
                q.push({tox, toy});
                ret += 1; 
                visited[tox][toy] = true;
            }
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%1d", &town[i][j]);
        }
    }    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(!visited[i][j] && town[i][j])
            {
                ans.push_back(bfs({i, j}));
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int u : ans) cout << u << '\n';
}