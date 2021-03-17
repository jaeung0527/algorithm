#include <bits/stdc++.h>

using namespace std;

int solve(int N, int M)
{
    if (N == 1)
    {
        return 1;
    }
    else if (N == 2)
    {
        int ans =  (M - 1) / 2 + 1 ;
        return ans > 4 ? 4 : ans;
    }
    else
    {
        if(M <= 4) return M;
        else if(M == 5 || M == 6) return 4;
        else return 5 + (M - 7);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    cout << solve(N, M);
}