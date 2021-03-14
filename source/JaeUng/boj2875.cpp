#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    while(K--)
    {
        if(N > M * 2)
            N -= 1;
        else
            M -= 1;
    }
    cout << min(M, N/2);

}