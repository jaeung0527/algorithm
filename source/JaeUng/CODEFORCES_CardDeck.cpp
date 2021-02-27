#include <bits/stdc++.h>

using namespace std;

int card[100001];
int idx[100001];
bool used[100001];

void solve(int n)
{
    int cpyCard[100001];
    copy(card + 1, card + 1 + n, cpyCard + 1); // 처음에 입력받은 카드 저장
    sort(card + 1, card + n + 1, [&](int u, int v){ return u > v; }); // 내림차순 정렬
    
    for(int i = 1, end = n; i <= n; i++) // 정렬된 카드에 대한 반복문
    {
        if(!used[card[i]])
        {
            int nextEnd = idx[card[i]] - 1;
            for(int j = idx[card[i]]; j <= end; j++) // 처음에 입력받은 카드에 대한 반복문
            {
                cout << cpyCard[j] << ' ';
                used[cpyCard[j]] = true;
            }
            end = nextEnd;
        }
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> card[i];
            idx[card[i]] = i;
        }
        solve(n);
        memset(card, 0, sizeof(card));
        memset(idx, 0 ,sizeof(idx));
        memset(used, false, sizeof(used)); // 배열 초기화
    }
}