#include <bits/stdc++.h>

using namespace std;

long long solve(long long p, long long a, long long b, long long c)
{
    long long ansA = p % a ? a * ((p / a) + 1) - p : a * ((p / a)) - p;
    long long ansB = p % b ? b * ((p / b) + 1) - p : b * ((p / b)) - p;
    long long ansC = p % c ? c * ((p / c) + 1) - p : c * ((p / c)) - p;
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