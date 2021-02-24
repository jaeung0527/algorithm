#include <bits/stdc++.h>

using namespace std;

long long solve(long long p, long long a, long long b, long long c)
{
    long long ansA = a - p >= 0 ? a - p : (p % a ? a * ((p / a) + 1) % p : 0);
    long long ansB = b - p >= 0 ? b - p : (p % b ? b * ((p / b) + 1) % p : 0);
    long long ansC = c - p >= 0 ? c - p : (p % c ? c * ((p / c) + 1) % p : 0);
    return min(ansA, min(ansB, ansC));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        long long p, a, b, c;
        cin >> p >> a >> b >> c;
        cout << solve(p, a, b, c) << '\n';
    }
}